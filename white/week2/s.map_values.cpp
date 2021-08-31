#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& mp) {
    set<string> st;
    for (const auto& m : mp) {
        st.insert(m.second);
    }
    return st;
}
