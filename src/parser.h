// parser.h
#ifndef PARSER_H
#define PARSER_H

#include "utils.h"

enum class Action { FIND, MATCH, EXTRACT, INVALID };
enum class PatternType { EMAIL, PHONE, URL, DIGIT, DATE, WORD, INVALID };
enum class SpecifierType { NONE, STARTS_WITH, ENDS_WITH, CONTAINS };

struct Query {
    Action action = Action::INVALID;
    PatternType pattern = PatternType::INVALID;
    SpecifierType spec = SpecifierType::NONE;
    string specValue;
};

// Parse tokens into Query object
Query parseQuery(const vector<string>& tokens);

#endif // PARSER_H
