#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<vector<string>> v(31);
    const vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    int previous_month = 0;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "ADD") {
            int i;
            cin >> i;
            string s;
            cin >> s;
            v[i - 1].push_back(s);
        }
        else if (command == "DUMP") {
            int i;
            cin >> i;
            cout << v[i - 1].size() << " ";
            for (string s : v[i - 1]) {
                cout << s << " ";
            }
            cout << endl;
        }
        else if (command == "NEXT") {
            ++current_month;
            current_month %= 12;
            if (days[current_month] > days[previous_month]) {
                v.resize(days[current_month]);
            }
            else if (days[current_month] < days[previous_month]) {
                int difference = days[previous_month] - days[current_month];
                int b = difference;
                for (int i = 0; i < difference; ++i) {
                    v[v.size() - b - 1].insert(end(v[v.size() - b - 1]), begin(v[v.size() - b]), end(v[v.size() - b]));
                    v.erase(v.begin() + v.size() - b);
                    --b;
                }
            }
            ++previous_month;
            previous_month %= 12;
        }
    }
    return 0;
}