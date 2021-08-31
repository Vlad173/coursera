#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    this->s.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(s), end(s));
        return s;
  }
private:
  vector<string> s;
};

