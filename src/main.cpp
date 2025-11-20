// // main.cpp
// #include <iostream>
// #include "lexer.h"
// #include "parser.h"
// #include "executor.h"

// int main() {
//     using std::cout; using std::cin; using std::getline;
//     cout << "==================== RegexQL ====================\n";
//     cout << "Examples:\n";
//     cout << "  find email\n";
//     cout << "  match phone number starting with +91\n";
//     cout << "  extract URL containing https\n";
//     cout << "Type 'exit' to quit.\n\n";

//     while (true) {
//         cout << "RegexQL> ";
//         string queryLine;
//         if (!std::getline(cin, queryLine)) break;
//         if (queryLine.empty()) continue;
//         if (toLower(queryLine) == "exit") break;

//         auto tokens = tokenize(queryLine);
//         Query q = parseQuery(tokens);

//         if (q.action == Action::INVALID || q.pattern == PatternType::INVALID) {
//             cout << " Invalid query. Expected: <action> <pattern> [specifier <value>]\n";
//             continue;
//         }

//         cout << "Enter sample text (single line):\n> ";
//         string sample;
//         if (!std::getline(cin, sample)) sample = "";

//         executeQuery(q, sample);
//         cout << "--------------------------------------------------\n";
//     }

//     cout << "Goodbye!\n";
//     return 0;
// }
#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "executor.h"

int main() {
    using std::cout;
    using std::cin;
    using std::getline;

    cout << "==================== RegexQL ====================\n";
    cout << "Examples:\n";
    cout << "  find email\n";
    cout << "  match phone number starting with +91\n";
    cout << "  extract URL containing https\n";
    cout << "Type 'exit' to quit.\n\n";

    while (true) {
        cout << "RegexQL> ";
        string queryLine;
        if (!getline(cin, queryLine)) break;
        if (queryLine.empty()) continue;
        if (toLower(queryLine) == "exit") break;

        auto tokens = tokenize(queryLine);
        Query q = parseQuery(tokens);

        if (q.action == Action::INVALID || q.pattern == PatternType::INVALID) {
            cout << "Invalid query. Expected: <action> <pattern> [specifier <value>]\n";
            continue;
        }

        cout << "Enter sample text (single line):\n> ";
        string sample;
        if (!getline(cin, sample)) sample = "";

        executeQuery(q, sample);
        cout << "--------------------------------------------------\n";
    }

    cout << "Goodbye!\n";
    return 0;
}
