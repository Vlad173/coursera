#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    // 1
    if (range_end - range_begin < 2) {
        return;
    }

    // 2
    vector<typename RandomIt::value_type> elements(range_begin, range_end);

    // 3 и 4
    MergeSort(begin(elements), begin(elements) + (end(elements) - begin(elements)) / 2);
    MergeSort(begin(elements) + (end(elements) - begin(elements)) / 2, end(elements));

    // 5
    merge(begin(elements), begin(elements) + (end(elements) - begin(elements)) / 2,
        begin(elements) + (end(elements) - begin(elements)) / 2, end(elements),
        range_begin);
}

int main() {
    vector<int> v = {5, 2, 7, 1, 10, 3, 9, 13};
    MergeSort(v.begin(), v.end());
    for (const int& i : v) {
        cout << i << ' ';
    }
    cout << endl;
    
    return 0;
}