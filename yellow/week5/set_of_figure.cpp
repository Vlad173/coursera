#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

#define PI 3.14

class Figure {
public: 
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(const double a, const double b, const double c) 
        : a_(a), b_(b), c_(c)
    {}

    string Name() const override {
        return "TRIANGLE";
    }

    double Perimeter() const override {
        return a_ + b_ + c_;
    }

    double Area() const override {
        double semi = (a_ + b_ + c_) / 2;
        return sqrt(semi * (semi - a_) * (semi - b_) * (semi - c_));
    }

private:
    const double a_, b_, c_;
};

class Rect : public Figure {
public:
    Rect(const double widht, const double height) 
        : width_(widht), height_(height) 
    {}
    
    string Name() const override {
        return "RECT";
    }

    double Perimeter() const override {
        return 2 * width_ + 2 * height_;
    }

    double Area() const override {
        return width_ * height_;
    }

private:
    const double width_;
    const double height_;
};

class Circle : public Figure {
public:
    Circle(const double r) : r_(r) {}

    string Name() const override {
        return "CIRCLE";
    }

    double Perimeter() const override {
        return 2 * PI * r_;
    }

    double Area() const override {
        return PI * r_ * r_;
    }

private:
    const double r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string s;
    is >> s;
    if (s == "RECT") {
        double a, b;
        is >> a >> b;
        return make_shared<Rect>(a, b);
    } else if (s == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c; 
        return make_shared<Triangle>(a, b, c);
    } else {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
        // Пропускаем "лишние" ведущие пробелы.
        // Подробнее об std::ws можно узнать здесь:
        // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}