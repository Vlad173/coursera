#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string first_name;
  string last_name;

  int day;
  int month;
  int year;
};

int main() {
    int N;
    cin >> N;
    vector<Student> students(N);
    for (Student& st : students) {
        cin >> st.first_name >> st.last_name >> st.day >> st.month >> st.year;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string request;
        int number;
        cin >> request >> number;
        --number;
        if (request == "name" && number >= 0 && number < N) {
            cout << students[number].first_name << " " << students[number].last_name << endl;
        }
        else if (request == "date" && number >= 0 && number < N) {
            cout << students[number].day << '.' << students[number].month << '.' << students[number].year << endl;
        }
        else {
            cout << "bad request" << endl;
        }
    }
    return 0;
    
}