#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main()
{
    int64_t sum = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& temp : v)
    {
        cin >> temp;
        sum += temp;
    }
    int avg = sum / n;
    vector<int> pos;
    for (int i = 0; i < n; ++i)
        if (v[i] > avg)
            pos.push_back(i);
    cout << pos.size() << endl;
    for (const int& i : pos)
        cout << i << " ";
    cout << endl;
    return (0);
}
