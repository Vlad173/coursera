#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cout << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

//int GetDistinctRealRootCount(double a, double b, double c) {
// Р’С‹ РјРѕР¶РµС‚Рµ РІСЃС‚Р°РІР»СЏС‚СЊ СЃСЋРґР° СЂР°Р·Р»РёС‡РЅС‹Рµ СЂРµР°Р»РёР·Р°С†РёРё С„СѓРЅРєС†РёРё,
  // С‡С‚РѕР±С‹ РїСЂРѕРІРµСЂРёС‚СЊ, С‡С‚Рѕ РІР°С€Рё С‚РµСЃС‚С‹ РїСЂРѕРїСѓСЃРєР°СЋС‚ РєРѕСЂСЂРµРєС‚РЅС‹Р№ РєРѕРґ
  // Рё Р»РѕРІСЏС‚ РЅРµРєРѕСЂСЂРµРєС‚РЅС‹Р№
//}


void Test() {
    {
        double a = 0, b = 0, c = 5; // линейное уравнение b = 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 0, "0.0.5");
    }

    {
        double a = 1, b = 3, c = 1; // D > 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 2, "1.3.1");
    }

    {
        double a = 1, b = 0, c = -25; // D > 0 b = 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 2, "1.0.-25");
    }

    {
        double a = 1, b = 5, c = 0; // D > 0 c = 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 2, "1.5.0");
    }

    {
        double a = 0.25, b = 0, c = 0; // D > 0 c = 0 b = 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 1, "0.25, 0, 0");
    }

    {
        double a = 1, b = 1, c = 1; // D < 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 0, "1.1.1");
    }

    {
        double a = 0, b = 25, c = 5; // линейное уравнение b != 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 1, "0.25.5");
    }

    {
        double a = 1, b = 2, c = 1; // D = 0
        AssertEqual(GetDistinctRealRootCount(a, b, c), 1, "1.2.1");
    }
}

int main() {
    TestRunner runner;
    runner.RunTest(Test, "Test");
    return 0;
}
