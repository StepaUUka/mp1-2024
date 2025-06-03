#include "functions.h"

Function::Function(const string& name) : name(name) {}

string Function::getName() const { return name; }

double Function::taylorSeries(double x, double eps, int maxTerms) const {
    double sum = first(x);
    double term = sum;

    for (int n = 2; n < maxTerms; n++) {
        double sum_prev = sum;
        term *= next(x, n);
        sum += term;

        if (abs(sum - sum_prev) < eps) {
            break;
        }
    }

    return sum;
}

vector<double> Function::evaluateOnInterval(double a, double b, double step) const {
    vector<double> results;
    for (double x = a; x <= b; x += step) {
        results.push_back(evaluate(x));
    }
    return results;
}

// SinFunction implementation
SinFunction::SinFunction() : Function("sin(x)") {}
double SinFunction::evaluate(double x) const { return sin(x); }
double SinFunction::first(double x) const { return x; }
double SinFunction::next(double x, int n) const { return -x * x / ((2 * n - 1) * (2 * n - 2)); }
double SinFunction::derivative(double x) const { return cos(x); }

// CosFunction implementation
CosFunction::CosFunction() : Function("cos(x)") {}
double CosFunction::evaluate(double x) const { return cos(x); }
double CosFunction::first(double x) const { return 1.0; }
double CosFunction::next(double x, int n) const { return -x * x / ((2 * n - 1) * (2 * n - 2)); }
double CosFunction::derivative(double x) const { return -sin(x); }

// ExpFunction implementation
ExpFunction::ExpFunction() : Function("exp(x)") {}
double ExpFunction::evaluate(double x) const { return exp(x); }
double ExpFunction::first(double x) const { return 1.0; }
double ExpFunction::next(double x, int n) const { return x / (n - 1); }
double ExpFunction::derivative(double x) const { return exp(x); }

// SinhFunction implementation
SinhFunction::SinhFunction() : Function("sinh(x)") {}
double SinhFunction::evaluate(double x) const { return sinh(x); }
double SinhFunction::first(double x) const { return x; }
double SinhFunction::next(double x, int n) const { return x * x / ((2 * n - 1) * (2 * n - 2)); }
double SinhFunction::derivative(double x) const { return cosh(x); }

// Processor implementation
Processor::Processor(const Function* func) : function(func) {}
double Processor::Taylor(double x, double eps) const { return function->taylorSeries(x, eps); }

void Processor::printOnInterval(double a, double b, double step) const {
    cout << "Функция " << function->getName() << " на отрезке ["
        << a << ", " << b << "] с шагом " << step << ":\n";

    auto values = function->evaluateOnInterval(a, b, step);
    for (size_t i = 0; i < values.size(); ++i) {
        double x = a + i * step;
        cout << fixed << setprecision(6)
            << "f(" << x << ") = " << values[i] << endl;
    }
}

double Processor::Integral(double a, double b, int n) const {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;
        sum += function->evaluate(x);
    }

    return sum * h;
}

void printMenu() {
    cout << "Выберите функцию:\n";
    cout << "1. sin(x)\n";
    cout << "2. cos(x)\n";
    cout << "3. exp(x)\n";
    cout << "4. sinh(x)\n";
    cout << "0. Выход\n";
}
