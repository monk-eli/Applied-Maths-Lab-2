#include "h/GradientDescent.h"
#include "h/Steps.h"
#include "h/ParabolaWithTwoArguments.h"

int main() {
    TwoDimensionalFunction *func = new ParabolaWithTwoArguments(10, 10);
    Step *stepFunction = new FractionizeStep(1);

    std::vector<double> result = GradientDescent(func, 0.001, stepFunction);

    for (int i = 0; i < 2; i++) {
        std::cout << result[i] << "\n";
    }

    return 0;
}
