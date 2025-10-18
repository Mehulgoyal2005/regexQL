// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include "utils.h"

// Tokenize the input query into phrase-aware tokens
// e.g., "phone number", "starting with" are kept as single tokens
vector<string> tokenize(const string &input);

#endif // LEXER_H
