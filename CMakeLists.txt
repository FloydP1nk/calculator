cmake_minimum_required(VERSION 3.23)
project(calculator)

set(CMAKE_CXX_STANDARD 23)

add_executable(calculator main.cpp convert_to_reverse_polish_notation.cpp header.hpp check_and_fix_errors.cpp trigonometry_calculation.cpp result_calculation.cpp)
