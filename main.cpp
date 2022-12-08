#include "header.hpp"

int main() {

    std::string input_exp; //Исходное выражение
    std::cout << "Please enter expression" << std::endl;
    //input_exp = "sin(x)*sin(x)+cos(x)*cos(x)";
    std::cin >> input_exp;

//    bool flag = false;
//    for (size_t i = 0; i < input_exp.size(); ++i) {
//        if (input_exp[i - 1] != 'e' && input_exp[i] == 'x' && input_exp[i + 1] != 'p') {
//            flag = true;
//        }
//    }
//    if (flag) {
//        std::cout << "Please enter x" << std::endl;
//        std::string x;
//        std::cin >> x;
//        for (size_t i = 0; i < input_exp.size(); ++i) {
//            if (input_exp[i - 1] != 'e' && input_exp[i] == 'x' && input_exp[i + 1] != 'p') {
//                input_exp.replace(i, x.size(), x);
//            }
//        }
//    }

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

