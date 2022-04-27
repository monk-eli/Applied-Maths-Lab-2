#include "h/Functions.h"
#include <cmath>
#include <vector>

 double ParabolaWithTwoArguments(std::vector<double> args) {
        return std::pow(args[0], 2) + 3*std::pow(args[1],2) - 2 * args[0]*args[1]+1;
    }

 std::vector<double> ParabolaWithTwoArgumentsGradient(std::vector<double> args) {
        std::vector<double> result;
        result.push_back(2*args[0]-2*args[1]);
        result.push_back(6*args[1]-2*args[0]);

        return result;
    }


