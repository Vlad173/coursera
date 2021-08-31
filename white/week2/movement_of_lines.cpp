#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    while(!source.empty()) {
        destination.push_back(source[0]);
        source.erase(source.begin());
    }
}

int main() {
    return 0;
}