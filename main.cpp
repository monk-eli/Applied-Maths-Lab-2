#include "h/Gradient_descent.h"
#include "h/Steps.h"
#include "h/ParabolaWithTwoArguments.h"

int main() {
   std::vector<double> result = GradientDescent(ParabolaWithTwoArguments(10, 10), 0.001, ConstantStep(0.01));

   for (int i = 0; i < 2; i++){
       std::cout << result[i] << "\n";
   }

    return 0;
}
