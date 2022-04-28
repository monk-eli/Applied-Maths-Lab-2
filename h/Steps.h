#ifndef APPLIED_MATHS_LAB_2_STEPS_H
#define APPLIED_MATHS_LAB_2_STEPS_H


double ConstantStep(double a);

class ConstantStep : public Step {
private:
    double a;
public:
    ConstantStep(double a);

    double get();

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};

class GoldenRatio : public Step {
private:
    double a;
public:
    GoldenRatio(double a);

    double get();

    double method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) override;
};

#endif //APPLIED_MATHS_LAB_2_STEPS_H