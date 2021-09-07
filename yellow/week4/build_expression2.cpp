#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    int x;
    int n;
    cin >> x >> n;
    string prev_operation = "/";
    deque<string> expression = {to_string(x)};
    for (int i = 0; i < n; ++i) {
        string operation;
        int num;
        cin >> operation >> num;
        if ((operation == "*" || operation == "/") && (prev_operation == "+" || prev_operation == "-")) {
            expression.push_front("(");
            expression.push_back(")");
        }
        expression.push_back(" ");
        expression.push_back(operation);
        expression.push_back(" ");
        expression.push_back(to_string(num));
        prev_operation = operation;
    }
    for (const string& i : expression) {
        cout << i;
    }
    cout << endl;
    return 0;
}