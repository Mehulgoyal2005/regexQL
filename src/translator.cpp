// translator.cpp
#include "translator.h"

string escapeForRegexLiteral(const string &s) {
    // minimal escaping for common regex metacharacters in specifier values
    string out;
    for (char c : s) {
        if (c == '.' || c == '^' || c == '$' || c == '*' || c == '+' || c == '?' ||
            c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '\\' || c == '|') {
            out.push_back('\\');
        }
        out.push_back(c);
    }
    return out;
}

string translateToRegex(const Query& q) {
    string base;
    switch (q.pattern) {
        case PatternType::EMAIL:
            base = R"([\w\.-]+@[\w\.-]+\.\w+)";
            break;
        case PatternType::PHONE:
            // simple phone template: optional +country and digits
            base = R"(\+?\d{1,3}[-\s]?\d{5,10})";
            break;
        case PatternType::URL:
            base = R"((https?:\/\/)?[\w\.-]+\.\w{2,})";
            break;
        case PatternType::DIGIT:
            base = R"(\d+)";
            break;
        case PatternType::DATE:
            // allows dd-mm-yyyy or dd/mm/yyyy or d-m-yy etc.
            base = R"(\b\d{1,2}[-\/]\d{1,2}[-\/]\d{2,4}\b)";
            break;
        case PatternType::WORD:
            base = R"(\b\w+\b)";
            break;
        default:
            return "";
    }

    // Apply specifier: we build a new pattern around base or transform to literal search
    if (q.spec == SpecifierType::STARTS_WITH && !q.specValue.empty()) {
        string lit = escapeForRegexLiteral(q.specValue);
        // If user asked "match phone number starting with +91"
        if (q.pattern == PatternType::PHONE) {
            // phone starting with literal prefix
            return "^" + lit + R"(\d*)";
        }
        // for other patterns, check that match begins with specValue
        return "(?:" + base + ")"; // default - keep base (caller can interpret). Simpler: search for base preceded by ^specValue
    } else if (q.spec == SpecifierType::ENDS_WITH && !q.specValue.empty()) {
        string lit = escapeForRegexLiteral(q.specValue);
        if (q.pattern == PatternType::PHONE) {
            return R"(\d*)" + lit + "$";
        }
        return "(?:" + base + ")";
    } else if (q.spec == SpecifierType::CONTAINS && !q.specValue.empty()) {
        string lit = escapeForRegexLiteral(q.specValue);
        // for contains we can search for the literal inside the match or simply search the text for base and literal together.
        // Simpler approach: require that matched substring contains the literal -> use lookahead
        return "(?=(.*" + lit + "))" + base;
    }

    return base;
}
