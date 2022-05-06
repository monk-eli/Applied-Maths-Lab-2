#include "h/GradientDescent.h"
#include "h/Steps.h"
#include "h/Functions.h"
#include "h/MinMethod.h"
#include "h/ConjugateGradient.h"

#include <fstream>

int main() {
    TwoDimensionalFunction *func = new ParabolaWithTwoArguments(10, 10);
    Step *FibStep = new Fibonacci(0.01, 0, 0.05, 0.001);
    Step *GRStep = new GoldenRatio(0.01, 0, 0.05, 0.001);
    Step *FStep = new FractionizeStep(0.1);
    Step *CStep = new ConstantStep(0.01);

    std::cout << "==========Constant Step==========\n";
    std::vector<std::vector<double>> result_1 = GradientDescent(func, 0.001, CStep);

    std::ofstream fout_1("/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-2/output-gradient/ConstantStepDescent");
    for (auto &i: result_1) {
        fout_1 << i[0] << "," << i[1] << '\n';
    }
    fout_1.close();


    std::cout << "==========Fractionize step==========\n";
    std::vector<std::vector<double>> result_2 = GradientDescent(func, 0.001, FStep);

    std::ofstream fout_2("/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-2/output-gradient/FractionizeStepDescent");
    for (auto &i: result_2) {
        fout_2 << i[0] << "," << i[1] << '\n';
    }
    fout_2.close();


    std::cout << "==========Golden Section Step==========\n";
    std::vector<std::vector<double>> result_3 = GradientDescent(func, 0.001, GRStep);

    std::ofstream fout_3("/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-2/output-gradient/GRStepDescent");
    for (auto &i: result_3) {
        fout_3 << i[0] << "," << i[1] << '\n';
    }
    fout_3.close();


    std::cout << "==========Fibonacci Step==========\n";
    std::vector<std::vector<double>> result_4 = GradientDescent(func, 0.001, FibStep);

    std::ofstream fout_4("/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-2/output-gradient/FibonacciStepDescent");
    for (auto &i: result_4) {
        fout_4 << i[0] << "," << i[1] << '\n';
    }
    fout_4.close();


    std::cout << "==========Conjugate Method==========\n";
    std::vector<double> x_prev = {
            100,
            100,
    };

    MinMethod *GRM = new GoldenRatioM();

    std::vector<std::vector<double>> result_5 = ConjGradMethod(func, 0.001, func->getArgs(), x_prev, GRM);

    std::ofstream fout_5(
            "/home/eliah/1.LABS/Applied Maths/Applied-Maths-Lab-2/output-gradient/ConjugateGradientDescent");
    for (auto &i: result_5) {
        fout_5 << i[0] << "," << i[1] << '\n';
    }
    fout_5.close();

    return 0;
}