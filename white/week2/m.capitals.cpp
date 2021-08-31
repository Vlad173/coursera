#include <iostream>
#include <map>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    map<string, string> directory;
    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country;
            string capital;
            cin >> country >> capital;
            if (directory.count(country) == 0) {
                directory[country] = capital;
                cout << "Introduce new country " << country << " with capital " << capital << endl;
            }
            else if (directory[country] == capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            }
            else {
                cout << "Country " << country << " has changed its capital from " << directory[country] << " to " << capital << endl;
                directory[country] = capital;
            }
        }
        else if (command == "RENAME") {
            string old_country;
            string new_country;
            cin >> old_country >> new_country;
            if (directory.count(old_country) == 0 || directory.count(new_country) == 1 || new_country == old_country) {
                cout << "Incorrect rename, skip" << endl;
            }
            else {
                directory[new_country] = directory[old_country];
                directory.erase(old_country);
                cout << "Country " << old_country << " with capital " << directory[new_country] << " has been renamed to " << new_country << endl;
            }
        }
        else if (command == "ABOUT") {
            string country;
            cin >> country;
            if (directory.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else {
                cout << "Country " << country << " has capital " << directory[country] << endl;
            }
        }
        else if (command == "DUMP") {
            if (directory.empty()) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (const auto& [key, value] : directory) {
                    cout << key << '/' << value << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}