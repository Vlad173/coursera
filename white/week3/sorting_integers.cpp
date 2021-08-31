#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> values(N);
    for (int& v : values) {
        cin >> v;
    }
    sort(begin(values), end(values), [] (int i, int j) {
        return abs(i) < abs(j);
    });

    for (const int& v : values) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}