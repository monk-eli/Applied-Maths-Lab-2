#include <vector>
#include "iostream"
#include "vector"

#ifndef APPLIED_MATHS_LAB_2_TWODIMENSIONALFUNCTION_H
#define APPLIED_MATHS_LAB_2_TWODIMENSIONALFUNCTION_H

class TwoDimensionalFunction {
public:
    virtual const std::vector<double> &getArgs() const = 0;

    virtual void setArgs(const std::vector<double> &args) = 0;

    virtual double Result(const std::vector<double> &args) = 0;

    virtual std::vector<double> Gradient(const std::vector<double> &args) = 0;
};

#endif //APPLIED_MATHS_LAB_2_TWODIMENSIONALFUNCTION_H