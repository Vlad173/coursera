#include <iostream>

using namespace std;

class Incognizable {
public:
    Incognizable() {}
    Incognizable(const int& a, const int& b) {
        this->a = a;
        this->b = b;
    }
    Incognizable(const int& a) {
        this->a = a;
    }
    void PrintIncogizable() const {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }

private:
    int a;
    int b;
};
