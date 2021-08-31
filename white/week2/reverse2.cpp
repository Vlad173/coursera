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

vector<int> Reversed(const vector<int>& v) {
    vector<int> a = v;
    Reverse(a);
    return a;
}

int main() {
    return 0;
}