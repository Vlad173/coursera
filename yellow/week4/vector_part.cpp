#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto it = find_if(begin(numbers), end(numbers), [](const int& number) {
        return number < 0;
    });
    
    while (it != begin(numbers)) {
        --it;
        cout << *it << ' ';
    }
}