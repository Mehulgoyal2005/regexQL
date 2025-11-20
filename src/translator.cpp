#include "translator.h"

// Escape literal text for regex
string escapeForRegexLiteral(const string &s) {
    string out;
    for (char c : s) {
        if (c == '.' || c == '^' || c == '$' || c == '*' || c == '+' || c == '?' ||
            c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' ||
            c == '\\' || c == '|') {
            out.push_back('\\');
        }
        out.push_back(c);
    }
    return out;
}

string translateToRegex(const Query& q) {
    string base;

    // ---------- BASE PATTERN ----------
    switch (q.pattern) {
        case PatternType::EMAIL:
            base = R"([\w\.-]+@[\w\.-]+\.\w+)";
            break;

        case PatternType::PHONE:
            base = R"(\+?\d{1,3}[-\s]?\d{5,10})";
            break;

        case PatternType::URL:
            base = R"((https?:\/\/)?[\w\.-]+\.\w{2,})";
            break;

        case PatternType::DIGIT:
            base = R"(\d+)";
            break;

        case PatternType::DATE:
            base = R"(\b\d{1,2}[-\/]\d{1,2}[-\/]\d{2,4}\b)";
            break;

        case PatternType::WORD:
            base = R"(\b\w+\b)";
            break;

        default:
            return "";
    }

    // If no specifier → return base
    if (q.spec == SpecifierType::NONE || q.specValue.empty())
        return base;

    string lit = escapeForRegexLiteral(q.specValue);

 
    //STARTS WITH

    if (q.spec == SpecifierType::STARTS_WITH) {
        if (q.pattern == PatternType::PHONE)
            return lit + R"(\d{5,10})";

        if (q.pattern == PatternType::WORD) {
            // Word starting with <lit>
            return R"(\b)" + lit + R"(\w*\b)";
        }

        return lit + base;
    }


    // ENDS WITH
    if (q.spec == SpecifierType::ENDS_WITH) {
        if (q.pattern == PatternType::PHONE)
            return R"(\+?\d{1,3}[-\s]?\d*)" + lit;

        if (q.pattern == PatternType::WORD) {
            // Word ending with <lit>
            return R"(\b\w*)" + lit + R"(\b)";
        }

        return base + lit;
    }


    // CONTAINS

    if (q.spec == SpecifierType::CONTAINS) {
        if (q.pattern == PatternType::WORD) {
            // Word containing <lit>
            return R"(\b\w*)" + lit + R"(\w*\b)";
        }

        // generic string “contains”
        return "(?=.*" + lit + ")" + base;
    }

    return base;
}
