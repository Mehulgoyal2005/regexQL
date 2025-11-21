// lexer.cpp
#include "lexer.h"

vector<string> tokenize(const string &input) {
    string low = toLower(input);
    vector<string> tokens = splitWords(low);
    vector<string> out;
    for (size_t i = 0; i < tokens.size(); i++) {
        if (i + 1 < tokens.size()) {
            string two = tokens[i] + " " + tokens[i+1];
            if (two == "phone number" || two == "starting with" || two == "ending with") {
                out.push_back(two);
                ++i;
                continue;
            }
        }
        out.push_back(tokens[i]);
    }
    return out;
}
