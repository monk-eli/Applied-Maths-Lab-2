#include "h/Steps.h"
#include "h/Functions.h"

#include <cmath>
#include <stdexcept>

double GoldenRatio::method(class TwoDimensionalFunction *f, std::vector<double> x_prev, double a) {
    if (this->left_border == 0 && this->right_border == 0)
        throw std::out_of_range("Drugoi ctr use pls");

    std::vector<double> resultPoints;
    const double fi = 1.6180339887;
    double x1, x2;
    double y1, y2;

    x1 = this->right_border - ((this->right_border - this->left_border) / fi);
    x2 = this->left_border + ((this->right_border - this->left_border) / fi);
    y1 = makeSimpleFunction(x1, f);
    y2 = makeSimpleFunction(x2, f);

    while (std::abs(this->right_border - this->left_border) > this->accuracy) {
        if (y1 <= y2) {
            this->right_border = x2;
            x2 = x1;
            x1 = this->right_border - ((this->right_border - this->left_border) / fi);
            y2 = y1;
            y1 = makeSimpleFunction(x1, f);
        } else {
            this->left_border = x1;
            x1 = x2;
            x2 = this->left_border + ((this->right_border - this->left_border) / fi);
            y1 = y2;
            y2 = makeSimpleFunction(x2, f);
        }
    }

    return (this->left_border + this->right_border) / 2;
}

double GoldenRatio::makeSimpleFunction(double some_x, class TwoDimensionalFunction *f) {
    std::vector<double> buffer;

    buffer.push_back(f->getArgs()[0] - some_x * f->Gradient(f->getArgs())[0]);
    buffer.push_back(f->getArgs()[1] - some_x * f->Gradient(f->getArgs())[1]);

    return f->Result(buffer);
}

GoldenRatio::GoldenRatio(double a) {
    this->a = a;
}

GoldenRatio::GoldenRatio(double a, double left_border, double right_border, double accuracy) {
    this->a = a;
    this->left_border = left_border;
    this->right_border = right_border;
    this->accuracy = accuracy;
}

double GoldenRatio::getFirstStep() {
    return this->a;
}