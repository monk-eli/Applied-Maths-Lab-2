#include "h/Gradient_descent.h"
#include "h/Functions.h"
#include "h/Steps.h"

std::vector<double> GradientDescent(double x, double y, double accuracy, double step) {
    int iteration = 0;
    std::vector<double> x_prev = {
            x, y,
    };

    std::vector<double> x_next = {
            x+accuracy, y+accuracy,
    };

    double a = ConstantStep(step);

    while (std::abs(ParabolaWithTwoArguments(x_next) - ParabolaWithTwoArguments(x_prev)) >= accuracy) {
        iteration++;

        x_prev = x_next;
        a = ConstantStep(step);
        std::vector<double> grad = ParabolaWithTwoArgumentsGradient(x_prev);

        for (int i = 0; i < 2; i++) {
               x_next[i] = x_prev[i]-a*grad[i];
        }
    }

    std::cout << "Iterations: " << iteration << "\n";
    return x_next;
}



