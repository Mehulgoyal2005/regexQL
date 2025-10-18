// translator.h
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "parser.h"
#include <string>

// Convert Query to a regex string
string translateToRegex(const Query& q);

#endif // TRANSLATOR_H
