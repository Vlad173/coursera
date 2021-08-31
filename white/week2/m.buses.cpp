#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    map<string, vector<string>> buses;
    vector<string> sequence;
    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            for (int j = 0; j < stop_count; ++j) {
                string stop;
                cin >> stop;
                buses[bus].push_back(stop);
            }
            sequence.push_back(bus);
        }
        else if (command == "BUSES_FOR_STOP") {
           string stop;
           cin >> stop;
           bool ok = false;
           for (const string& s1 : sequence) {
               for (const string& s2 : buses[s1]) {
                   if (stop == s2) {
                       ok = true;
                       cout << s1 << " ";
                       break;
                   }
               }
           }
           if (!ok) {
               cout << "No stop";
           }
           cout << endl;
        }
        else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus) == 0) {
                cout << "No bus" << endl;
            }
            else {
                for (const string& stop : buses[bus]) {
                    cout << "Stop " << stop << ": ";
                    bool ok = false;
                    for (const string& s1 : sequence) {
                        if (s1 == bus) {
                            continue;
                        }
                        for (const string& s2 : buses[s1]) {
                            if (stop == s2) {
                                ok = true;
                                cout << s1 << " ";
                                break;
                            }
                        }
                    }
                    if (!ok) {
                        cout << "no interchange";
                    }
                    cout << endl;
                }

            }
        }
        else if (command == "ALL_BUSES") {
            if (buses.empty()) {
                cout << "No buses" << endl;
            }
            else {
                for (const auto& [bus, stops] : buses) {
                    cout << "Bus " << bus << ": ";
                    for (const string& stop : buses[bus]) {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}
    