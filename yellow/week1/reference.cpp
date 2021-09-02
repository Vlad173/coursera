#include <iostream>
#include <map>
#include <exception>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key key) {
    if (m.find(key) == m.end()) {
        throw runtime_error("");
    }
    else {
        return m.at(key);
    }
}

