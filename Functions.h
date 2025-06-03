#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class Function {
protected:
    string name;
public:
    Function(const string& name);
    virtual ~Function() = default;

    string getName() const;
    virtual double evaluate(double x) const = 0;
    virtual double first(double x) const = 0;
    virtual double next(double x, int n) const = 0;
    virtual double derivative(double x) const = 0;
    virtual double taylorSeries(double x, double eps, int maxTerms = 1000) const;
    vector<double> evaluateOnInterval(double a, double b, double step) const;
};

class SinFunction : public Function {
public:
    SinFunction();
    double evaluate(double x) const override;
    double first(double x) const override;
    double next(double x, int n) const override;
    double derivative(double x) const override;
};

class CosFunction : public Function {
public:
    CosFunction();
    double evaluate(double x) const override;
    double first(double x) const override;
    double next(double x, int n) const override;
    double derivative(double x) const override;
};

class ExpFunction : public Function {
public:
    ExpFunction();
    double evaluate(double x) const override;
    double first(double x) const override;
    double next(double x, int n) const override;
    double derivative(double x) const override;
};

class SinhFunction : public Function {
public:
    SinhFunction();
    double evaluate(double x) const override;
    double first(double x) const override;
    double next(double x, int n) const override;
    double derivative(double x) const override;
};

class Processor {
private:
    const Function* function;
public:
    Processor(const Function* func);
    double Taylor(double x, double eps) const;
    void printOnInterval(double a, double b, double step) const;
    double Integral(double a, double b, int n = 1000) const;
};

void printMenu();

#endif
