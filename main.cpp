#include "header.hpp"

int main() {
    std::string input_exp; //Исходное выражение
    std::cout << "Please enter expression" << std::endl;
    //input_exp = "sin(12345)*sin(12345)+cos(12345)*cos(12345)";
    std::cin >> input_exp;
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

