#include "h/Steps.h"
#include "h/Functions.h"
#include <cmath>

double FractionizeStep::method(class TwoDimensionalFunction *f, std::vector<double> x_prev, double a) {
    double e = 0.01;

    std::vector<double> x_next = x_prev;
    std::vector<double> grad = f->Gradient(x_prev);

    for (int i = 0; i < 2; i++) {
        x_next[i] = x_prev[i] - a * grad[i];
    }

    double grad_sum;

    for (int i = 0; i < 2; i++) {
        grad_sum += std::pow(grad[i], 2);
    }

    while (f->Result(x_prev) - f->Result(x_next) < e * a * grad_sum) {
        a *= 0.95;

        for (int i = 0; i < 2; i++) {
            x_next[i] = x_prev[i] - a * grad[i];
        }
    }

    return a;
}

FractionizeStep::FractionizeStep(double a) {
    FractionizeStep::a = a;
}

double FractionizeStep::getFirstStep() {
    return FractionizeStep::a;
}