#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    map<set<string>, int> buses;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int n;
        cin >> n;
        set<string> st;
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            st.insert(s);
        }
        if (buses.count(st) == 1) {
            cout << "Already exists for " << buses[st] << endl;
        }
        else {
            const int size = buses.size();
            buses[st] = size + 1;
            cout << "New bus " << size + 1 << endl;
        }
    }
    return 0;
}