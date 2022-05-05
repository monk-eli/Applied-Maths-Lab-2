#include "Steps.h"
#include "Functions.h"

#include <vector>

#ifndef APPLIED_MATHS_LAB_2_CONJUGATEGRADIENT_H
#define APPLIED_MATHS_LAB_2_CONJUGATEGRADIENT_H

std::vector<std::vector<double>> ConjGradMethod(class TwoDimensionalFunction *f, double error, std::vector<double> x,
                                                std::vector<double> x_prev, class MinMethod *minMethod);

double DotProduct(std::vector<double> vec1, std::vector<double> vec2);

double VectorNorm(std::vector<double> vec);

class NeededFunction {
private:
    TwoDimensionalFunction *f;
    std::vector<double> args;
    std::vector<double> direction;

public:
    NeededFunction(TwoDimensionalFunction *f, std::vector<double> args, std::vector<double> direction);

    double result(double a);

    double SWM();
};

#endif //APPLIED_MATHS_LAB_2_CONJUGATEGRADIENT_H
