#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> days(N);
    vector<int> result;
    int sum = 0;
    for (int& i : days) {
        cin >> i;
        sum += i;
    }
    double average = sum / N;
    for (int i = 0; i < N; ++i) {
        if (days[i] > average) {
            result.push_back(i);
        }
    }

    cout << result.size() << endl;
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}