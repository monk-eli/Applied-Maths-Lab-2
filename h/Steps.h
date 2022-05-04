#ifndef APPLIED_MATHS_LAB_2_STEPS_H
#define APPLIED_MATHS_LAB_2_STEPS_H

#include <vector>

class Step {
public:
    virtual double getFirstStep() = 0;
    virtual double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) = 0;
};

class ConstantStep : public Step {
private:
    double a;
public:
    ConstantStep(double a);

    double getFirstStep() override;

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};

class FractionizeStep : public Step {
private:
    double a;
public:
    FractionizeStep(double a);

    double getFirstStep() override;

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};

class GoldenRatio : public Step {
private:
    double a;
    double left_border = 0;
    double right_border = 0;
    double accuracy;
public:
    GoldenRatio(double a);

    GoldenRatio(double a, double left_border, double right_border, double accuracy);

    double makeSimpleFunction(double x, class TwoDimensionalFunction *f);

    double getFirstStep() override;

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};

class Fibonacci : public Step {
private:
    double a;
    double left_border = 0;
    double right_border = 0;
    double accuracy;
public:
    Fibonacci(double a);

    Fibonacci(double a, double left_border, double right_border, double accuracy);

    double getFirstStep() override;

    double makeSimpleFunction(double some_x, class TwoDimensionalFunction *f);

    double fibonacciNumberFunction(double n);

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};


#endif //APPLIED_MATHS_LAB_2_STEPS_H