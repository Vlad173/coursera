#include <iostream>
#include <vector>

using namespace std;

class FunctionPart {
public:
    FunctionPart(const char& operation, const double& value) {
        this->operation = operation;
        this->value = value;
    }
    double Apply(double value) const {
        if (operation == '+') {
            return value + this->value;
        }
        else if (operation == '*') {
            return value * this->value;
        }
        else if (operation == '/') {
            return value / this -> value;
        }
        else {
            return value - this->value;
        }
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        }
        else if (operation == '-') {
            operation = '+';
        }
        else if (operation == '*') {
            operation = '/';
        }
        else {
            operation = '*';
        }
    }
public:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(const char& operation, const double& value) {
        parts.push_back({operation, value});
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
public: 
    vector<FunctionPart> parts;
};
struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}
