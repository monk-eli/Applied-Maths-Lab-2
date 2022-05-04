cmake_minimum_required(VERSION 3.21)
project(Applied_Maths_Lab_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Applied_Maths_Lab_2 main.cpp GradientDescent.cpp h/GradientDescent.h h/Steps.h ParabolaWithTwoArguments.cpp h/Functions.h ConstantStep.cpp FractionizeStep.cpp GoldenRatio.cpp Fibonacci.cpp ConjugateGradient.cpp h/ConjugateGradient.h h/MinMethod.h MinMethod.cpp)
