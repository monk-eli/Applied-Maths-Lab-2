#include "h/GradientDescent.h"
#include "h/Steps.h"
#include "h/Functions.h"

int main() {
    TwoDimensionalFunction *func = new ParabolaWithTwoArguments(10, 10);
    Step *FibStep = new Fibonacci(1, 0, 0.05, 0.001);
    Step *GRStep = new GoldenRatio(1, 0, 0.05, 0.001);
    Step *FStep = new FractionizeStep(1);
    Step *CStep = new ConstantStep(0.01);

    std::cout << "==========Constant Step==========\n";
    std::vector<double> result_3 = GradientDescent(func, 0.001, CStep);

    for (int i = 0; i < 2; i++) {
        std::cout << "| " << result_3[i] << "\n";
    }
    std::cout << "==========Fractionize step==========\n";
    std::vector<double> result_2 = GradientDescent(func, 0.001, FStep);

    for (int i = 0; i < 2; i++) {
        std::cout << "| " << result_2[i] << "\n";
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
