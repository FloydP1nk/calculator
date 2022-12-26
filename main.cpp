#include "header.hpp"

int main() {

    std::string input_exp; //Исходное выражение
    std::cout << "Please enter expression" << std::endl;
    //input_exp = "(tg(x)*tg(x)*cos(x)*cos(x)+ctg(x)*ctg (x)*sin(x)*sin(x))*27/(12-3)"; основное триг. тождество * 3 = 3
    //std::cin >> input_exp;
    getline(std::cin, input_exp);

    bool flag = false;
    // Поиск переменной x
    for (size_t i = 0; i < input_exp.size(); ++i) {
        if (input_exp[i - 1] != 'e' && input_exp[i] == 'x' && input_exp[i + 1] != 'p') {
            flag = true;
        }
    }
    if (flag) { // Если x был найден
        std::cout << "Please enter x" << std::endl;
        std::string x;
        std::cin >> x;
        for (size_t i = 0; i < input_exp.size(); ++i) {
            if (input_exp[i - 1] != 'e' && input_exp[i] == 'x' && input_exp[i + 1] != 'p') {
                input_exp.erase(i,1);
                input_exp.insert(i,x);
            }
        }
    }

    input_exp = check_and_fix(input_exp); //Проверка выражения
    std::cout << "Выражение после проверки " << input_exp << std::endl;
    if (input_exp == "ERROR") {
        std::cout << "ERROR : OpenBracketCount != CloseBracketCount" << std::endl;
    } else {
        std::string output_exp = convert(input_exp); //Преобразование в обратную польскую запись
        std::cout << "Выражение после преобразования " << output_exp << std::endl;
        double result = result_calc(output_exp); //Вычисление преобразованного выражения
        std::cout << "result is " << result;
    }
    return 0;
}

