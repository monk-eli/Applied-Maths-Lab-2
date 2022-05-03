#include "Functions.h"
#include "Steps.h"
#include <vector>

#ifndef APPLIED_MATHS_LAB_2_CONJUGATEGRADIENT_H
#define APPLIED_MATHS_LAB_2_CONJUGATEGRADIENT_H

double SWM()

void ConjGradMethod(class TwoDimensionalFunction *f, double error, std::vector<double> x,
        std::vector<double> x_prev, Step *minMethod);

#endif //APPLIED_MATHS_LAB_2_CONJUGATEGRADIENT_H
