#include <cmath>
#include <stdexcept>
#include "h/Steps.h"
#include "h/Functions.h"

Fibonacci::Fibonacci(double a){
    this->a = a;
}

Fibonacci::Fibonacci(double a, double left_border, double right_border, double accuracy){
    this->a = a;
    this->left_border = left_border;
    this->right_border = right_border;
    this->accuracy = accuracy;
}

double Fibonacci::getFirstStep() {
    return a;
}

double Fibonacci::makeSimpleFunction(double some_x, class TwoDimensionalFunction *f) {
    std::vector<double> buffer;

    buffer.push_back(f->getArgs()[0] - some_x * f->Gradient(f->getArgs())[0]);
    buffer.push_back(f->getArgs()[1] - some_x * f->Gradient(f->getArgs())[1]);

    return f->Result(buffer);
}

double Fibonacci::fibonacciNumberFunction(double n) {
    return 1 / std::sqrt(5) * (pow(((1 + std::sqrt(5)) / 2),n) - pow(((1 - std::sqrt(5)) / 2),n));
}

double Fibonacci::method(class TwoDimensionalFunction *f, std::vector<double> prev_x, double a_step) {
    if (this->left_border == 0 && this->right_border == 0)
        throw std::out_of_range("Drugoi ctr use pls");

    double a = this->left_border, b = this->right_border;
    int n = (b - a) / this->accuracy;

    double x1 = a + (fibonacciNumberFunction(n) / fibonacciNumberFunction(n + 2)) * (b - a);
    double x2 = a + (fibonacciNumberFunction(n + 1) / fibonacciNumberFunction(n + 2)) * (b - a);
    double y1 = makeSimpleFunction(x1, f);
    double y2 = makeSimpleFunction(x2, f);

    while(b - a > this->accuracy){
        if(y1 <= y2){
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = a + (fibonacciNumberFunction(n) / fibonacciNumberFunction(n + 2)) * (b - a);
            y1 = makeSimpleFunction(x1, f);
        }
        else {
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = a + (fibonacciNumberFunction(n + 1) / fibonacciNumberFunction(n + 2)) * (b - a);
            y2 = makeSimpleFunction(x2, f);
        }
    }

    return (a + b) / 2;
}