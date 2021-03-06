#include "h/Functions.h"


#include <cmath>
#include <vector>

ParabolaWithTwoArguments::ParabolaWithTwoArguments(double x, double y) {
    ParabolaWithTwoArguments::args = {
            x,
            y,
    };
}

const std::vector<double> &ParabolaWithTwoArguments::getArgs() const {
    return args;
}

void ParabolaWithTwoArguments::setArgs(const std::vector<double> &args) {
    ParabolaWithTwoArguments::args = args;
}

double ParabolaWithTwoArguments::Result(const std::vector<double> &args) {
    return std::pow(args[0], 2) + 3 * std::pow(args[1], 2) - 2 * args[0] * args[1] + 1;
}

std::vector<double> ParabolaWithTwoArguments::Gradient(const std::vector<double> &args) {
    std::vector<double> result{
            2 * args[0] - 2 * args[1],
            6 * args[1] - 2 * args[0]
    };

    return result;
}

std::vector<double> ParabolaWithTwoArguments::AntiGradient(const std::vector<double> &args) {
    std::vector<double> result{
            -2 * args[0] + 2 * args[1],
            -6 * args[1] + 2 * args[0]
    };

    return result;
}