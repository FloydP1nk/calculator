//
// Created by Pavel Erokhin on 02.12.2022.
//

#include "header.hpp"

double result_calc(std::string input_exp) {
    double result;
    std::string number;
    std::stack<double> stack_num; // Стек для чисел
    for (size_t i = 0; i < input_exp.size(); i++) {
        //result = 0;
        char temp_symb = input_exp[i];
        if (((temp_symb >= 48) && (temp_symb <= 57)) || (temp_symb == '.')) {  //Если числа
            number += temp_symb;
            if (input_exp[i + 1] == ' ' || input_exp[i + 1] == '*' || input_exp[i + 1] == '/' ||
                input_exp[i + 1] == '+' || input_exp[i + 1] == '-') {
                stack_num.push(std::stod(number));
                number = "";
            }
        } else if (temp_symb == '*' || temp_symb == '/' || temp_symb == '+' || temp_symb == '-') {
            double num2 = stack_num.top();
            stack_num.pop();
            double num1 = stack_num.top();
            stack_num.pop();
            if (temp_symb == '+' || temp_symb == '-') {
                result = temp_symb == '+' ? num1 + num2 : num1 - num2;
            } else {
                result = temp_symb == '*' ? num1 * num2 : num1 / num2;
            }
            stack_num.push(result);
        }
    }
    result = stack_num.top();
    return result;
}
