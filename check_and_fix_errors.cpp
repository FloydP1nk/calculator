//
// Created by Pavel Erokhin on 02.12.2022.
//

#include "header.hpp"

std::string check_and_fix(std::string input_exp) {
    for (size_t i = 0; i < input_exp.size(); i++) {
        if (input_exp[i] == ' ') {
            input_exp.erase(i, 1); // Удаляем пробелы
            --i;
        }
    }
    if (input_exp[0] == '-') { // Если самый первый символ '-'
        input_exp.erase(0, 1);
        input_exp.insert(0, 1, '(');
        input_exp.insert(1, 1, '0');
        input_exp.insert(2, 1, '-');
        input_exp.insert(3, 1, '1');
        input_exp.insert(4, 1, ')');
        input_exp.insert(5, 1, '*');
    }
    int OpenBracketCount = 0, CloseBracketCount = 0; //Счетчики скобок
    for (size_t i = 0; i < input_exp.size(); i++) {
        if (input_exp[i] == ',') {
            input_exp.replace(i, 1, "."); // Меняем ',' на '.'
        }
        if (input_exp[i] == '(') {  // Проверем скобки
            if (input_exp[i + 1] == '-') {
                input_exp.insert(i + 1, 1, '0'); //Ставим 0 перед '-'
            }
            OpenBracketCount += 1;
        } else if (input_exp[i] == ')') {
            CloseBracketCount += 1;
        }
    }
    if (OpenBracketCount != CloseBracketCount) {
        return "ERROR";
    } else {
        return input_exp;
    }
}