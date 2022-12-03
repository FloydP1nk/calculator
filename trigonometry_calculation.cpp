//
// Created by Pavel Erokhin on 02.12.2022.
//

#include "header.hpp"

#define _USE_MATH_DEFINES

std::string trig_calc(std::string input_exp) {
    for (size_t i = 0; i < input_exp.size(); i++) {
        if (input_exp[i] == 's' && input_exp[i + 1] == 'i' && input_exp[i + 2] == 'n') {
            std::string inner_exp;
            size_t j = i + 4;
            int close_bracket_pos = 0;
            while (input_exp[j] != ')') {
//               TODO рекурсия?
                inner_exp += input_exp[j];//Формируем выражение аргумента
                close_bracket_pos += 1;
                j++;
            }
            close_bracket_pos += 1;
            double res = result_calc(convert(inner_exp));//Вычисляем результат аргумента
            res = sin(res * M_PI / 180);//Вычисляем sin от аргумента
            std::string str_res = "(";
            str_res += std::to_string(res);
            str_res += ")";

            input_exp.replace(i + 4, close_bracket_pos, str_res);//Меняем sin(...) на rs

        } else if (input_exp[i] == 'c' && input_exp[i + 1] == 'o' && input_exp[i + 2] == 's') {


        } else if (input_exp[i] == 't' && input_exp[i + 1] == 'g') {

        } else if (input_exp[i] == 'c' && input_exp[i + 1] == 't' && input_exp[i + 2] == 'g') {

        }
    }
    return input_exp;
}