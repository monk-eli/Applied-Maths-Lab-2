#ifndef APPLIED_MATHS_LAB_2_MINMETHOD_H
#define APPLIED_MATHS_LAB_2_MINMETHOD_H

#include <vector>
#include <cmath>

const double D = 0.00000005;

class MinMethod {
public:
    virtual std::vector<double> result(class NeededFunction f, double left_border, double right_border, double eps) = 0;
};

class DichotomyM : public MinMethod {
private:
    const double D = 0.00000005;
public:
    std::vector<double> result(class NeededFunction f, double left_border, double right_border, double eps) override;
};

class GoldenRatioM : public MinMethod {
private:
    const double GR = (1 + std::sqrt(5)) / 2;
public:
    std::vector<double> result(class NeededFunction f, double left_border, double right_border, double eps) override;
};

class FibonacciM : public MinMethod {
private:
    double fibonacciNumberFunction(double n) {
        return 1 / std::sqrt(5) * (pow(((1 + std::sqrt(5)) / 2), n) - pow(((1 - std::sqrt(5)) / 2), n));
    }

public:
    std::vector<double> result(class NeededFunction f, double left_border, double right_border, double eps) override;
};

class ParabolaM : public MinMethod {
public:
    std::vector<double> result(class NeededFunction f, double left_border, double right_border, double eps) override;
};

class BrentM : public MinMethod {
private:
    const double GR = (1 + std::sqrt(5)) / 2;
    const double GR_REV = (3 - std::sqrt(5)) / 2;
public:
    std::vector<double> result(class NeededFunction f, double left_border, double right_border, double eps) override;
};

#endif //APPLIED_MATHS_LAB_2_MINMETHOD_H
