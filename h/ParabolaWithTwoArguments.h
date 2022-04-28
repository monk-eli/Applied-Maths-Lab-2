//
// Created by Ado! on 28.04.2022.
//

#ifndef APPLIED_MATHS_LAB_2_PARABOLAWITHTWOARGUMENTS_H
#define APPLIED_MATHS_LAB_2_PARABOLAWITHTWOARGUMENTS_H


#include <vector>

class ParabolaWithTwoArguments {
private:
    std::vector<double> args;

public:
    ParabolaWithTwoArguments(double x, double y);

    double Result(const std::vector<double> &args);

    std::vector<double> Gradient(const std::vector<double> &args);

    const std::vector<double> &getArgs() const;

    void setArgs(const std::vector<double> &args);

};

#endif //APPLIED_MATHS_LAB_2_PARABOLAWITHTWOARGUMENTS_H
