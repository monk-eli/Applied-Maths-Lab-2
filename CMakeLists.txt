cmake_minimum_required(VERSION 3.21)
project(Applied_Maths_Lab_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Applied_Maths_Lab_2
        main.cpp
        h/GradientDescent.h
        h/Steps.h
        h/ConjugateGradient.h
        h/MinMethod.h
        h/Functions.h
        GradientDescent.cpp
        ParabolaWithTwoArguments.cpp
        ConstantStep.cpp
        FractionizeStep.cpp
        GoldenRatio.cpp
        Fibonacci.cpp
        ConjugateGradient.cpp
        MinMethod.cpp)
