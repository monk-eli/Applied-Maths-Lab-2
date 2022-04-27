cmake_minimum_required(VERSION 3.21)
project(Applied_Maths_Lab_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Applied_Maths_Lab_2 main.cpp Gradient_descent.cpp h/Gradient_descent.h Functions.cpp h/Functions.h Steps.cpp h/Steps.h)
