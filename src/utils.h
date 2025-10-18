// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h>
using namespace std;

inline string toLower(const string &s) {
    string r = s;
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    return r;
}

inline vector<string> splitWords(const string &s) {
    vector<string> out;
    string cur;
    for (char c : s) {
        if (isspace((unsigned char)c)) {
            if (!cur.empty()) { out.push_back(cur); cur.clear(); }
        } else cur.push_back(c);
    }
    if (!cur.empty()) out.push_back(cur);
    return out;
}

#endif // UTILS_H
