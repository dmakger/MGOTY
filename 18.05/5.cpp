#include <iostream>
#include <string>

// Рекурсивная функция для подсчета количества цифр в строке
int DigitCount(const std::string& str) {
    // Базовый случай: если строка пуста, возвращаем 0
    if (str.empty()) {
        return 0;
    }
    
    // Рекурсивный случай: добавляем 1 к результату и вызываем функцию с оставшейся частью строки
    return 1 + DigitCount(str.substr(1));
}

int main() {
    std::string input;
    
    // Запрос ввода строки у пользователя
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    
    // Вызов функции для подсчета количества цифр в строке
    int count = DigitCount(input);
    
    // Вывод результата
    std::cout << "Количество цифр в строке: " << count << std::endl;
    
    return 0;
}
