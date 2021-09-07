#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = N; i >= 1; --i) {
        v.push_back(i);
    }

    do {
        for (const int& elem : v) {
            cout << elem << ' ';
        }
        cout << endl;
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}