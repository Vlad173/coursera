#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <class T>
T Sqr(T a);

template <class first, class second>
pair<first, second> operator*(const pair<first, second>& lhs, const pair<first, second>& rhs) ;

template <class key, class value>
map<key, value> operator*(const map<key, value>& lhs, const map<key, value>& rhs);

template <class T>
vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs);

template <class T>
vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs) {
    vector<T> result;
    for (const T& value : lhs) {
        result.push_back(value * value);
    }
    return result;
}

template <class first, class second>
pair<first, second> operator*(const pair<first, second>& lhs, const pair<first, second>& rhs) {
    return {lhs.first * lhs.first, lhs.second * lhs.second};
}

template <class key, class value>
map<key, value> operator*(const map<key, value>& lhs, const map<key, value>& rhs) {
    map<key, value> a;
    for (const auto& m : lhs) {
        a[m.first] = m.second * m.second; 
    }
    return a;
}



template <class T>
T Sqr(T a) {
    return a * a;
}


int main() {
vector<int> v = {1, 2, 3};
cout << "vector:";
for (int x : Sqr(v)) {
  cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
cout << "map of pairs:" << endl;
for (const auto& x : Sqr(map_of_pairs)) {
  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
} 
}