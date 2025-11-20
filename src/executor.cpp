// // executor.cpp
// #include "executor.h"
// #include <regex>
// #include <iostream>

// void executeQuery(const Query& q, const string& text) {
//     string pattern = translateToRegex(q);
//     if (pattern.empty()) {
//         cout << " Unsupported pattern or invalid query.\n";
//         return;
//     }

//     // Print generated regex
//     cout << "\nGenerated regex: " << pattern << "\n";
//     cout << "Matches:\n";

//     try {
//         regex re(pattern);
//         smatch match;
//         string::const_iterator searchStart(text.cbegin());
//         bool found = false;
//         while (regex_search(searchStart, text.cend(), match, re)) {
//             found = true;
//             cout  << match[0] << "\n";
//             // move forward
//             searchStart = match.suffix().first;
//         }
//         if (!found) cout << "No matches found.\n";
//     } catch (const regex_error &e) {
//         cout << "Regex error: " << e.what() << "\n";
//     }
// }


// #include "executor.h"
// #include <regex>
// #include <iostream>

// void executeQuery(const Query& q, const std::string& text) {
//     std::string pattern = translateToRegex(q);
//     if (pattern.empty()) {
//         std::cout << "Unsupported pattern or invalid query.\n";
//         return;
//     }

//     // Print generated regex
//     std::cout << "\nGenerated regex: " << pattern << "\n";
//     std::cout << "Matches:\n";

//     try {
//         std::regex re(pattern);
//         std::smatch match;
//         auto searchStart = text.cbegin();
//         bool found = false;
//         int count = 0;

//         while (std::regex_search(searchStart, text.cend(), match, re)) {
//             found = true;
//             ++count;
//             std::cout << count << ") " << match[0] << "\n";
//             searchStart = match.suffix().first;
//         }

//         if (!found) {
//             std::cout << "No matches found.\n";
//         }
//     } catch (const std::regex_error &e) {
//         std::cout << "Regex error: " << e.what() << "\n";
//     }
// }

#include "executor.h"
#include <regex>
#include <iostream>

void executeQuery(const Query& q, const std::string& text) {
    std::string pattern = translateToRegex(q);
    if (pattern.empty()) {
        std::cout << "Unsupported pattern or invalid query.\n";
        return;
    }

    std::cout << "\nGenerated regex: " << pattern << "\n";
    std::cout << "Matches: \n";

    try {
        std::regex re(pattern);
        std::smatch match;
        auto searchStart = text.cbegin();
        bool found = false;

        while (std::regex_search(searchStart, text.cend(), match, re)) {
            found = true;
            std::cout << match.str(0) << "\n";  // <-- ONLY pure text printed
            searchStart = match.suffix().first;
        }

        if (!found) {
            std::cout << "No matches found.\n";
        }

    } catch (const std::regex_error &e) {
        std::cout << "Regex error: " << e.what() << "\n";
    }
}
