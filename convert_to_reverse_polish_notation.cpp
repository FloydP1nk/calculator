//
// Created by Pavel Erokhin on 02.12.2022.
//
#include "header.hpp"

std::string convert(std::string input_exp) {
    std::stack<operations> stack_oper; // Стек для мат операций
    std::string output_exp;
    std::string number;

    for (size_t i = 0; i < input_exp.size(); i++) {
        char temp_symb = input_exp[i];
        if (((temp_symb >= 48) && (temp_symb <= 57)) || (temp_symb == '.')) {  //Если числа
            number += temp_symb;
            if (!(((input_exp[i + 1] >= 48) && (input_exp[i + 1] <= 57)) ||
                  (input_exp[i + 1] == '.'))) { //Если следующий символ не число и не точка
                output_exp += number; //Пихаем number в выходдную строку
                output_exp += ' '; //Ставим пробел после числя ( для разделения )
                number = ""; //Обнуляем number
            }
        } else if (temp_symb == '*' || temp_symb == '/' || temp_symb == '+' || temp_symb == '-' || temp_symb == '(' ||
                   //Если текущий символ операция
                   temp_symb == ')') {
            operations symbolFromExp;
            symbolFromExp.symb = temp_symb; //Добовляем приоритет текущей операцие
            if (temp_symb == '*' || temp_symb == '/') { // Умножение или деление
                symbolFromExp.priority = 3;
                if (stack_oper.empty() || (stack_oper.top().priority <
                                           symbolFromExp.priority)) { //Если stack_oper пуст, или приоритет операции в стеке < приоритета текущей операции
                    stack_oper.push(symbolFromExp); //Пихаем текущую операцию в stack_oper
                } else {
                    while (stack_oper.top().priority >= symbolFromExp.priority) { //Пока приоритет операции в стеке >= приоритета текущей операции
                        output_exp += stack_oper.top().symb; //Пихаем операции стека в выходдную строку
                        stack_oper.pop(); // Удаляем операцию из стека TODO CHECK
                    }
                    stack_oper.push(symbolFromExp); //Пихаем в стек текущую операцию
                }
            } else if (temp_symb == '+' || temp_symb == '-') { //Сложение или вычитание
                symbolFromExp.priority = 2;
                if (stack_oper.empty() || (stack_oper.top().priority <
                                           symbolFromExp.priority)) { // Приоритет символа в стеке < symbolFromExp.priority
                    stack_oper.push(symbolFromExp);
                } else {
                    while (stack_oper.top().priority >= symbolFromExp.priority) {
                        output_exp += stack_oper.top().symb;
                        stack_oper.pop();
                    }
                    stack_oper.push(symbolFromExp);
                }
            } else if (temp_symb == '(') {
                symbolFromExp.priority = 1;
                stack_oper.push(symbolFromExp);
            } else if (temp_symb == ')') {
                while (stack_oper.top().symb != '(') {
                    output_exp += stack_oper.top().symb;
                    stack_oper.pop();
                }
                stack_oper.pop(); // Удаляем '('
            }
        }
    }
    output_exp += number;// Добовляем последнее число

    while (!std::empty(stack_oper)) { //Пихаем в выходную строку оставшиеся элеметы стека
        output_exp += stack_oper.top().symb;
        stack_oper.pop();
    }
    return output_exp;
}