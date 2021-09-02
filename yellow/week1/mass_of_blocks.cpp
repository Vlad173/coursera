#include <iostream>

using namespace std;

int main() {
    int n, r, w, h, d;
    uint64_t sum = 0;
    cin >> n >> r;
    for (int i = 0; i < n; ++i)
    {
        cin >> w >> h >> d;
        sum += static_cast<uint64_t>(w) * h * d;
    }
    sum *= r;
    cout << sum << endl;
    return 0;
}
