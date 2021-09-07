#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    auto first = begin(s);;
    auto second = find(s.begin(), s.end(), ' ');
    vector<string> words;
    while (second != s.end()) {
        words.push_back({first, second});
        first = second;
        ++first;
        second = find(first, s.end(), ' ');
    }
    words.push_back({first, second});
    return words;
}
