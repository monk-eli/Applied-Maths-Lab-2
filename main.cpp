#include "h/GradientDescent.h"
#include "h/Steps.h"
#include "h/Functions.h"

int main() {
    TwoDimensionalFunction *func = new ParabolaWithTwoArguments(10, 10);
    Step *stepFunction = new FractionizeStep(1);

    std::vector<double> result = GradientDescent(func, 0.001, stepFunction);

    for (int i = 0; i < 2; i++) {
        std::cout << result[i] << "\n";
    }
    std::cout << "==========Golden Section Step==========\n";
    std::vector<double> result = GradientDescent(func, 0.001, GRStep);

    for (int i = 0; i < 2; i++) {
        std::cout << "| " << result[i] << "\n";
    }

    std::cout << "==========Fibonacci Step==========\n";
    std::vector<double> result_4 = GradientDescent(func, 0.001, FibStep);

    for (int i = 0; i < 2; i++) {
        std::cout << "| " << result_4[i] << "\n";
    }

    return 0;
}
