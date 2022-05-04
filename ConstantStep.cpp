#include "h/Functions.h"
#include "h/Steps.h"

double ConstantStep::method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) {
    return this->a;
}

ConstantStep::ConstantStep(double a) {
    this->a = a;
}

double ConstantStep::getFirstStep() {
    return this->a;
}