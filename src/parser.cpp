// parser.cpp
#include "parser.h"

Query parseQuery(const vector<string>& tokens) {
    Query q;
    if (tokens.empty()) return q;

    // parse action
    string a = tokens[0];
    if (a == "find") q.action = Action::FIND;
    else if (a == "match") q.action = Action::MATCH;
    else if (a == "extract") q.action = Action::EXTRACT;
    else { q.action = Action::INVALID; return q; }

    if (tokens.size() < 2) { q.action = Action::INVALID; return q; }

    // pattern
    string p = tokens[1];
    if (p == "email") q.pattern = PatternType::EMAIL;
    else if (p == "phone number") q.pattern = PatternType::PHONE;
    else if (p == "url" || p == "website") q.pattern = PatternType::URL;
    else if (p == "digit") q.pattern = PatternType::DIGIT;
    else if (p == "date") q.pattern = PatternType::DATE;
    else if (p == "word") q.pattern = PatternType::WORD;
    else { q.pattern = PatternType::INVALID; return q; }

    // no specifier
    if (tokens.size() == 2) return q;

    // specifier should be token 2
    string sp = tokens[2];
    if (sp == "starting with") q.spec = SpecifierType::STARTS_WITH;
    else if (sp == "ending with") q.spec = SpecifierType::ENDS_WITH;
    else if (sp == "containing") q.spec = SpecifierType::CONTAINS;
    else { q.spec = SpecifierType::NONE; return q; }

    if (tokens.size() >= 4) q.specValue = tokens[3];
    return q;
}
