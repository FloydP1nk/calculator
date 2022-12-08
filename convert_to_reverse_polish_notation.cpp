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
        } else if (temp_symb == '*' || temp_symb == '/' || temp_symb == '+' || temp_symb == '-') {
            operations symb_from_exp;
            symb_from_exp.symb = temp_symb;
            /// Расставляем приоритеты
            if (temp_symb == '*' || temp_symb == '/') {
                symb_from_exp.priority = 3;
                symb_from_exp.symb = temp_symb == '*' ? '*' : '/';
            } else {
                symb_from_exp.priority = 2;
                symb_from_exp.symb = temp_symb == '+' ? '+' : '-';
            }
            if (stack_oper.empty() || (stack_oper.top().priority <
                                       symb_from_exp.priority)) { //Если stack_oper пуст, или приоритет операции в стеке < приоритета текущей операции
                stack_oper.push(symb_from_exp); //Пихаем текущую операцию в stack_oper
            } else {
                while (!stack_oper.empty() && (stack_oper.top().priority >=
                                               symb_from_exp.priority)) { //Пока приоритет операции в стеке >= приоритета текущей операции
                    output_exp += stack_oper.top().symb; //Пихаем операции стека в выходдную строку
                    stack_oper.pop(); // Удаляем операцию из стека
                }
                stack_oper.push(symb_from_exp); //Пихаем в стек текущую операцию
            }
        } else if (temp_symb == '(') {
            operations symb_from_exp;
            symb_from_exp.symb = temp_symb;
            symb_from_exp.priority = 1;
            stack_oper.push(symb_from_exp);
        } else if (temp_symb == ')') {
            while (stack_oper.top().symb != '(') {
                output_exp += stack_oper.top().symb;
                stack_oper.pop();
            }
            stack_oper.pop(); // Удаляем '('
            /// Тригонометрия
        } else if (input_exp[i] == 's' && input_exp[i + 1] == 'i' && input_exp[i + 2] == 'n') { /// sin
            operations trig_func;
            trig_func.priority = 4;
            trig_func.symb = 's';
            if (stack_oper.empty() || (stack_oper.top().priority < trig_func.priority)) {
                stack_oper.push(trig_func);
            } else {
                while (stack_oper.top().priority >= trig_func.priority) {
                    output_exp += stack_oper.top().symb;
                    stack_oper.pop();
                }
                stack_oper.push(trig_func);
            }
        } else if (input_exp[i] == 'c' && input_exp[i + 1] == 'o' && input_exp[i + 2] == 's') { /// cos
            operations trig_func;
            trig_func.priority = 4;
            trig_func.symb = 'c';
            if (stack_oper.empty() || (stack_oper.top().priority < trig_func.priority)) {
                stack_oper.push(trig_func);
            } else {
                while (stack_oper.top().priority >=
                       trig_func.priority) {
                    output_exp += stack_oper.top().symb;
                    stack_oper.pop();
                }
                stack_oper.push(trig_func);
            }
        } else if (input_exp[i] == 't' && input_exp[i + 1] == 'g' && input_exp[i - 1] != 'c') { /// tg
            operations trig_func;
            trig_func.priority = 4;
            trig_func.symb = 't';
            if (stack_oper.empty() || (stack_oper.top().priority < trig_func.priority)) {
                stack_oper.push(trig_func);
            } else {
                while (!stack_oper.empty() && stack_oper.top().priority >= trig_func.priority) {
                    output_exp += stack_oper.top().symb;
                    stack_oper.pop();
                }
                stack_oper.push(trig_func);
            }
        } else if (input_exp[i] == 'c' && input_exp[i + 1] == 't' && input_exp[i + 2] == 'g') { /// ctg
            operations trig_func;
            trig_func.priority = 4;
            trig_func.symb = 'q';
            if (stack_oper.empty() || (stack_oper.top().priority < trig_func.priority)) {
                stack_oper.push(trig_func);
            } else {
                while (stack_oper.top().priority >= trig_func.priority) {
                    output_exp += stack_oper.top().symb;
                    stack_oper.pop();
                }
                stack_oper.push(trig_func);
            }
        } else if (input_exp[i] == 'e' && input_exp[i + 1] == 'x' && input_exp[i + 2] == 'p') {
            operations trig_func;
            trig_func.priority = 4;
            trig_func.symb = 'e';
            if (stack_oper.empty() || (stack_oper.top().priority < trig_func.priority)) {
                stack_oper.push(trig_func);
            } else {
                while (stack_oper.top().priority >= trig_func.priority) {
                    output_exp += stack_oper.top().symb;
                    stack_oper.pop();
                }
                stack_oper.push(trig_func);
            }
        }
    }
    output_exp += number;// Добовляем последнее число
    while (!stack_oper.empty()) { //Пихаем в выходную строку оставшиеся элеметы стека
        output_exp += stack_oper.top().symb;
        stack_oper.pop();
    }
    return output_exp;
}