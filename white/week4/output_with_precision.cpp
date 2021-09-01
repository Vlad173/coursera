#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");

    float one;
    float two;
    float three;
    while (input >> one) {
        cout << fixed << setprecision(3) << one << endl;
    }
    //cout << fixed << setprecision(3) << one << endl << two << endl << three;
    return 0;
}