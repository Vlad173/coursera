#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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
    MergeSort(begin(elements), begin(elements) + (end(elements) - begin(elements)) / 3);
    MergeSort(begin(elements) + (end(elements) - begin(elements)) / 3, begin(elements) + (end(elements) - begin(elements)) / 3 * 2);
    MergeSort(begin(elements) + (end(elements) - begin(elements)) / 3 * 2, end(elements));


    // 5
    vector<typename RandomIt::value_type> temp;
    merge(begin(elements), begin(elements) + (end(elements) - begin(elements)) / 3,
        begin(elements) + (end(elements) - begin(elements)) / 3, begin(elements) + (end(elements) - begin(elements)) / 3 * 2,
        back_inserter(temp));

    merge(begin(temp), end(temp),
        begin(elements) + (end(elements) - begin(elements)) / 3 * 2, end(elements),
        range_begin);
}

/* int main() {
    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    MergeSort(v.begin(), v.end());
    for (const int& i : v) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
} */