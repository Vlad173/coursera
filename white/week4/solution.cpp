#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(const int& new_year, const int& new_month, const int& new_day) {
        if (new_month > 12 || new_month < 1) {
            throw out_of_range("Month value is invalid: " + to_string(new_month));
        }
        else if (new_day > 31 || new_day < 1) {
            throw out_of_range("Day value is invalid: " + to_string(new_day));
        }
        year = new_year;
        month = new_month;
        day = new_day;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
     if (lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();
    }
    if (lhs.GetMonth() != rhs.GetMonth()){
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetDay() < rhs.GetDay();
}

Date ParseDate(const string& date) {
    istringstream date_stream(date);
    int year, month, day;
    bool flag = true;

    flag = flag && (date_stream >> year);
    if (date_stream.peek() != '-') {
        flag = false;
    }
    date_stream.ignore(1);
    
    flag = flag && (date_stream >> month);
    if (date_stream.peek() != '-') {
        flag = false;
    }
    date_stream.ignore(1);
    
    flag = flag && (date_stream >> day);
    
    if (!date_stream.eof()) {
        flag = false;
    }

    if (!flag) {
        throw logic_error("Wrong date format: " + date);
    }

    return Date(year, month, day);
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << '-'
           << setw(2) << setfill('0') << date.GetMonth() << '-' 
           << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        if (!event.empty()) {
            events[date].insert(event);
        }
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (events[date].count(event) > 0 && events.count(date) > 0) {
            events[date].erase(event);
            return true;
        }
        else {
            return false;
        }
    }
    int DeleteDate(const Date& date) {
        int size = 0;
        if (events.count(date) > 0) {
            size = events.at(date).size();
            events.erase(date);
        }
        return size;
    }
    set<string> Find(const Date& date) const {
        set<string> result;
        if (events.count(date) > 0) {
            result = events.at(date);
        }
        return result;
    }

    void Print() const {
        for (const auto& [date, set] : events) {
            for (const string& event : set) {
                cout << date << " " << event << endl;
            }
        }
    }
    map<Date, set<string>> GetEvents() const {
        return events;
    }
private:
    map<Date, set<string>> events;
};

ostream& operator<<(ostream& stream, const Database& db) {
    for (const auto& [date, set] : db.GetEvents()) {
        for (const string& event : set) {
            stream << date << " " << event << endl;
        }
    }
    return stream;
}

int main() {
    string command;
    Database db;
    while (getline(cin, command)) {
        try {
            if (command == "") {
                continue;
            }
            stringstream input(command);
            string operation;
            input >> operation;
            if (operation == "Add") {
                Date date;
                string event;
                string date_string;
                input >> date_string >> event;
                date = ParseDate(date_string);
                db.AddEvent(date, event);
            }
            else if (operation == "Del") {
                Date date;
                string date_string;
                input >> date_string;
                date = ParseDate(date_string);
                if (!input.eof()) {
                    string event;
                    input >> event;
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    }
                    else {
                        cout << "Event not found" << endl;
                    }
                }
                else {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;    
                }
            }
            else if (operation == "Find") {
                Date date;
                string date_string;
                input >> date_string;
                date = ParseDate(date_string);
                set<string> events = db.Find(date);
                for (const string& event : events) {
                    cout << event << endl;
                }
            }
            else if (operation == "Print") {
                db.Print();
            }
            else {
                cout << "Unknown command: " << operation << endl;
            }

        } catch(exception& ex) {
            cout << ex.what() << endl;
        }
    }
    return 0;
}