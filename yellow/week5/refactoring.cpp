#include <iostream>
#include <string>
#include <vector>

using namespace std;

class People {
public:
    People(const string type, const string name) 
        : Type(type), Name(name) {}

    virtual void Walk(string destination) const {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
    }

    const string Type, Name;
};

class Student : public People {
public:

    Student(string name, string favouriteSong) 
        : People("Student", name), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << Type << ": " << Name << " learns" << endl;
    }

    void Walk(string destination) const override {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << Type << ": " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public People {
public:

    Teacher(string name, string subject) 
        : People("Teacher", name), Subject(subject) {}

    void Teach() const {
        cout << Type << ": " << Name << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public People {
public:
    Policeman(string name) 
        : People("Policeman", name) {}

    void Check(const People& p) {
        cout << Type << ": " << Name << " checks " << p.Type << ". " << p.Type << "'s name is: " << p.Name << endl;
    }

};

void VisitPlaces(const People& p, vector<string> places) {
    for (const string& place : places) {
        p.Walk(place);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    s.Walk("Kazan");
    s.Learn();
    s.SingSong();

    VisitPlaces(t, {"Moscow", "London"});
    t.Teach();

    Policeman p2("Jack");
    VisitPlaces(p, {"Moscow", "London"});
    p.Check(p2);
    p.Check(s);
    p.Check(t);

    return 0;
}
