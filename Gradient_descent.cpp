#include "h/Gradient_descent.h"
#include "h/Functions.h"
#include "h/Steps.h"
#include "h/ParabolaWithTwoArguments.h"

std::vector<double> GradientDescent(class ParabolaWithTwoArguments f, double accuracy, double step) {
    int iteration = 0;

    std::vector<double> x_prev = f.getArgs();

    std::vector<double> x_next = x_prev;

    double a = ConstantStep(step);

    std::vector<double> grad = f.Gradient(x_prev);

    for (int i = 0; i < 2; i++) {
        x_next[i] = x_prev[i]-a*grad[i];
    }

    while (std::abs(f.Result(x_next) - f.Result(x_prev)) >= accuracy) {
        iteration++;

        x_prev = x_next;
        a = ConstantStep(step);
        std::vector<double> grad = f.Gradient(x_prev);

        for (int i = 0; i < 2; i++) {
               x_next[i] = x_prev[i]-a*grad[i];
        }
    }

    std::cout << "Iterations: " << iteration << "\n";
    return x_next;
}



