#include "h/GradientDescent.h"
#include "h/Functions.h"
#include "h/Steps.h"

#include <numeric>

std::vector<std::vector<double>> GradientDescent(class TwoDimensionalFunction *f, double accuracy, class Step *step) {
    int iteration = 0;
    std::vector<double> ratios;
    std::vector<std::vector<double>> trajectory;

    double ratio = 0;

    std::vector<double> x_prev = f->getArgs();

    std::vector<double> x_next = x_prev;

    double a = step->getFirstStep();

    std::vector<double> grad = f->Gradient(x_prev);

    trajectory.push_back(x_next);

    for (int i = 0; i < 2; i++) {
        x_next[i] = x_prev[i] - a * grad[i];
    }

    trajectory.push_back(x_next);

    while (std::abs(f->Result(x_next) - f->Result(x_prev)) >= accuracy) {
        iteration++;

        x_prev = x_next;
        a = step->method(f, x_prev, a);
        grad = f->Gradient(x_prev);

        for (int i = 0; i < 2; i++) {
            x_next[i] = x_prev[i] - a * grad[i];
        }

        double xRatioPlusYBBetter = x_next[0] / x_prev[0];
        double yRatioPlusYBBetter = x_next[1] / x_prev[1];

        ratio = (xRatioPlusYBBetter + yRatioPlusYBBetter) / 2;
        ratios.push_back((ratio) / 2);
        trajectory.push_back(x_next);

        // std::cout << "| Dot: " << x_next[0] << " " << x_next[1] << "| Ratio:" << std::abs(ratio) << "\n";
    }

    std::cout << "| Result: " << x_next[0] << " " << x_next[1] << "\n";
    std::cout << "| Iterations: " << iteration << "\n";
    std::cout << "| Speed: " << std::abs(std::accumulate(ratios.begin(), ratios.end(), 0.0) / double(ratios.size()))
              << "\n";
    return trajectory;
}