#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& new_s) {
        s = new_s;
    }
    string ToString() const {
        return s;
    }
    void Reverse() {
        reverse(s.begin(), s.end());
    }

private:
    string s;
};
