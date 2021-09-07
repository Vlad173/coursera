#include <iostream>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    const auto first_not_less = numbers.lower_bound(border);
    if (first_not_less == begin(numbers)) {
        return first_not_less;
    }

    const auto first_less = prev(first_not_less);
    if (first_not_less == end(numbers)) {
        return first_less;
    }

    if (border - *first_less <= *first_not_less - border) {
        return first_less;
    }
    else {
        return first_not_less;
    }
}


int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}