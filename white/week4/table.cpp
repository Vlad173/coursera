#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    int n, m;
    input >> n >> m;
    int val;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            input >> val;
            input.ignore(1);
            cout << setw(10) << val << ' ';
        }
        input >> val;
        input.ignore(1);
        cout << setw(10) << val << endl;
        
    }
    return 0;
}