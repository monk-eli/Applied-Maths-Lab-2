#ifndef APPLIED_MATHS_LAB_2_FUNCTIONS_H
#define APPLIED_MATHS_LAB_2_FUNCTIONS_H

#include <vector>



class TwoDimensionalFunction {
public:
    virtual const std::vector<double> &getArgs() const = 0;

    virtual void setArgs(const std::vector<double> &args) = 0;

    virtual double Result(const std::vector<double> &args) = 0;

    virtual std::vector<double> Gradient(const std::vector<double> &args) = 0;
};

class ParabolaWithTwoArguments : public TwoDimensionalFunction {
private:
    std::vector<double> args;

public:
    ParabolaWithTwoArguments(double x, double y);

    double Result(const std::vector<double> &args);

    std::vector<double> Gradient(const std::vector<double> &args);

    const std::vector<double> &getArgs() const;

    void setArgs(const std::vector<double> &args);

};

#endif //APPLIED_MATHS_LAB_2_FUNCTIONS_H