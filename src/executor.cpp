// executor.cpp
#include "executor.h"
#include <regex>
#include <iostream>

void executeQuery(const Query& q, const string& text) {
    string pattern = translateToRegex(q);
    if (pattern.empty()) {
        cout << "❌ Unsupported pattern or invalid query.\n";
        return;
    }

    // Print generated regex
    cout << "\nGenerated regex: " << pattern << "\n";
    cout << "Matches:\n";

    try {
        regex re(pattern);
        smatch match;
        string::const_iterator searchStart(text.cbegin());
        bool found = false;
        while (regex_search(searchStart, text.cend(), match, re)) {
            found = true;
            cout << " → " << match[0] << "\n";
            // move forward
            searchStart = match.suffix().first;
        }
        if (!found) cout << "No matches found.\n";
    } catch (const regex_error &e) {
        cout << "Regex error: " << e.what() << "\n";
    }
}
