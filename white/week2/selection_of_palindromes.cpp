#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;
    bool ok = true;
    for (string s : words) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                ok = false;
            }
        }
        if (ok && s.size() >= minLength) {
            result.push_back(s);
        }
        else {
            ok = true;
        }
    }
    return result;
}

int main() {
    /* vector<string> words;
    words.push_back("abacaba");
    words.push_back("aba");
    vector<string> result = PalindromFilter(words, 5);
    for (string s : result) {
        cout << s << " ";
    } */
    return 0;
}