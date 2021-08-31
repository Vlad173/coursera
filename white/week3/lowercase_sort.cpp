#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> v(N);
    for (string& s : v) {
        cin >> s;
    }

    sort(begin(v), end(v), [] (string s1, string s2) {
        for (char& c : s1) {
            c = tolower(c);
        }
        for (char& c : s2) {
            c = tolower(c);
        }
        return s1 < s2;
    });

    for (const string& s : v) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}