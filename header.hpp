//
// Created by Pavel Erokhin on 02.12.2022.
//

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

class operations {
public :
    char symb;
    int priority;
};

#ifndef CALCULATOR_HEADER_HPP
#define CALCULATOR_HEADER_HPP

std::string check_and_fix(std::string input_exp);
std::string trig_calc(std::string input_exp);
std::string convert(std::string input_exp);
double result_calc(std::string input_exp);

#endif //CALCULATOR_HEADER_HPP
