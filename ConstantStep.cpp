#include "h/Functions.h"
#include "h/Steps.h"

double ConstantStep::method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a) {
    return ConstantStep::a;
}

ConstantStep::ConstantStep(double a) {
    ConstantStep::a = a;
}

double ConstantStep::getFirstStep() {
    return this->a;
}