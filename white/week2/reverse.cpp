#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    for (int i = 0; i < v.size() / 2; ++i) {
        int temp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = temp;
    }
}

int main() {
    vector<int> v;
    for (int i = 0; i < 4; ++i) {
        v.push_back(i);
    }
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    Reverse(v);

    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}