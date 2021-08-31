#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    map<string, set<string>> syn;
    string word1, word2;
    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "ADD") {
            cin >> word1 >> word2;
            syn[word1].insert(word2);
            syn[word2].insert(word1);
        }
        else if (command == "COUNT") {
            cin >> word1;
            cout << syn[word1].size() << endl;
        }
        else if (command == "CHECK") {
            cin >> word1 >> word2;
            if (syn[word1].count(word2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}