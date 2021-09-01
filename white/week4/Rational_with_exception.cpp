#include <iostream>
#include <sstream>
#include <map>
#include <exception>
#include <set>
#include <vector>
typedef long long ll;

using namespace std;


int GreatestCommonDivisor(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }
    Rational(ll numerator, ll denominator) {
        if (denominator == 0) {
            throw invalid_argument("invalid_argument"); 
        }
        const ll gcd = GreatestCommonDivisor(numerator, denominator);
        p = numerator / gcd;
        q = denominator / gcd;
        if (denominator < 0) {
            p = -p;
            q = -q;
        }
    }
    ll Numerator() const {
        return p;
    }
    ll Denominator() const {
        return q;
    }
private:
    ll p;
    ll q;
};

bool operator<(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return lhs.Numerator() < rhs.Numerator();
    }
    else {
        return lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator();
    }
}
bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() + rhs.Numerator(), lhs.Denominator()};
    }
    else {
        return {lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(), 
        lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() - rhs.Numerator(), lhs.Denominator()};
    }
    else {
        return {lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator(), 
        lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("domain_error");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rat) {
    stream << rat.Numerator() << '/' << rat.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rat) {
    int n, d;
    char c;
    if (stream) {
        stream >> n >> c >> d;
    }
    if (stream && c == '/') {
        rat = Rational(n, d);
    }

    return stream;
}

