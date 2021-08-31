#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<vector<string>, int> buses;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int n;
        cin >> n;
        vector<string> vec;
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            vec.push_back(s);
        }
        if (buses.count(vec) == 1) {
            cout << "Already exists for " << buses[vec] << endl;
        }
        else {
            int size = buses.size();
            buses[vec] = size + 1;
            cout << "New bus " << size + 1 << endl;
        }
    }
    return 0;
}