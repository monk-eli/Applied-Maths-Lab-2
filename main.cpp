#include "h/Gradient_descent.h"
#include "h/Steps.h"

int main() {


   std::vector<double> result = GradientDescent(10, 11, 0.001, ConstantStep(0.01));
   for (int i = 0; i < 2; i++){
       std::cout << result[i] << "\n";
   }

    return 0;
}
