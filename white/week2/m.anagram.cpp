#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
    map <char, int> counters;
    for (const char& c : word) {
        ++counters[c];
    }
    return counters;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string first;
        string second;
        cin >> first >> second;
        if (BuildCharCounters(first) == BuildCharCounters(second)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}