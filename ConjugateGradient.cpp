#include "h/Functions.h"
#include "h/Steps.h"
#include "h/ConjugateGradient.h"
#include "h/MinMethod.h"
#include <cmath>
#include <utility>
#include <stdexcept>
#include <numeric>
#include <iostream>

NeededFunction::NeededFunction(TwoDimensionalFunction *f, std::vector<double> args, std::vector<double> direction) {
    this->f = f;
    this->args = std::move(args);
    this->direction = std::move(direction);
}

double NeededFunction::result(double a) {
    std::vector<double> buffer{
            args[0] + a * direction[0],
            args[1] + a * direction[1],
    };

    return f->Result(buffer);
}

double NeededFunction::SWM() {
    double h = 0.01;
    double a0 = 0;

    while (!((this->result(a0 - h) > this->result(a0)) && (this->result(a0 + h)
                                                           > this->result(a0)))) {
        if (this->result(a0 + h) > this->result(a0))
            a0 = a0 - h / 2;
        else
            a0 = a0 + h / 2;
    }

    return a0;
}


double DotProduct(std::vector<double> vec1, std::vector<double> vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::logic_error("Vectors are different in size");
    }

    double result = 0;

    for (int i = 0; i < vec1.size(); i++) {
        result += vec1[i] * vec2[i];
    }

    return result;
}

double VectorNorm(std::vector<double> vec) {
    return std::sqrt(DotProduct(vec, vec));
}


std::vector<double> ConjGradMethod(class TwoDimensionalFunction *f, double error, std::vector<double> x,
        std::vector<double> x_prev, class MinMethod *minMethod) {

    std::vector<double> direction {
            0, 0,
    };

    int iteration = 0;
    double beta = 0;
    std::vector<std::vector<double>> tracking;

    while (std::abs(f->Result(x) - f->Result(x_prev)) > error) {
        iteration += 1;

        std::vector<double> xGrad = f->Gradient(x);

        double normVector = std::sqrt(std::pow(-xGrad[0] + beta * direction[0], 2)
                                      + std::pow(-xGrad[1] + beta * direction[1], 2));

        direction = {
                -xGrad[0] + beta * direction[0] / normVector,
                -xGrad[1] + beta * direction[1] / normVector,
        };

        NeededFunction func(f, x, direction);

        std::vector<double> result = minMethod->result(func, 0, func.SWM(), error);
        double alpha = (result[0] + result[1]) / 2;

        x_prev = x;
        std::vector<double> xPrevGrad = f->Gradient(x_prev);

        tracking.push_back(x);
        x[0] = x[0] + alpha * direction[0];
        x[1] = x[1] + alpha * direction[1];
        beta = DotProduct(xGrad, xPrevGrad) / std::pow(VectorNorm(xPrevGrad), 2);
    }

    std::cout << "| Iterations: " << iteration << "\n";
    return x;
}