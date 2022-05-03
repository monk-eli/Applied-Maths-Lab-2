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

    double getFirstStep();

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};

class FractionizeStep : public Step {
private:
    double a;
public:
    FractionizeStep(double a);

    double getFirstStep();

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};

#endif //APPLIED_MATHS_LAB_2_STEPS_H