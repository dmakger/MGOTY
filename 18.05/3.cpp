#include <iostream>
#include <string>

int DigitCount(const std::string& S) {
    // Базовый случай: если строка пустая, возвращаем 0
    if (S.empty()) {
        return 0;
    }
    
    // Рекурсивный случай: добавляем 1, если первый символ строки является цифрой,
    // и вызываем функцию DigitCount для оставшейся части строки
    return std::isdigit(S[0]) + DigitCount(S.substr(1));
}

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::cin >> input;

    int count = DigitCount(input);
    std::cout << "Количество цифр: " << count << std::endl;

    return 0;
}
