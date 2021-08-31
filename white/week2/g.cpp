#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
    for (auto v : m) {
        cout << v.first << " " << v.second << endl;
    }
    m[2] = "two";
    m.erase(1);
    m[3] = "three";
    m.erase(4);
    m[5] = "five";
    cout << m.size() << endl;
    for (auto v : m) {
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}