#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> people;
    int n;
    int i;
    string s;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        cin >> s;
        if (s == "WORRY_COUNT") {
            int count = 0;
            for (bool b : people) {
                if (b) {
                    ++count;
                }
            }
            cout << count << endl;
        }
        else {
            cin >> i;
            if (s == "COME") {
                people.resize(people.size() + i, false);
            }
            else if (s == "WORRY") {
                people[i] = true;
            }
            else if (s == "QUIET") {
                people[i] = false;
            }
        }
    }

    return 0;
}