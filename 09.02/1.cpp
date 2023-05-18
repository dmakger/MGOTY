#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    // Ввод коэффициентов уравнения
    std::cout << "Введите коэффициент a: ";
    std::cin >> a;

    std::cout << "Введите коэффициент b: ";
    std::cin >> b;

    std::cout << "Введите коэффициент c: ";
    std::cin >> c;

    // Вычисление дискриминанта
    discriminant = b * b - 4 * a * c;

    // Проверка значения дискриминанта
    if (discriminant > 0) {
        // Два различных корня
        root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Корень 1: " << root1 << std::endl;
        std::cout << "Корень 2: " << root2 << std::endl;
    } else if (discriminant == 0) {
        // Один корень (дискриминант равен нулю)
        root1 = -b / (2 * a);
        std::cout << "Корень: " << root1 << std::endl;
    } else {
        // Комплексные корни (дискриминант отрицательный)
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        std::cout << "Корень 1: " << realPart << " + " << imaginaryPart << "i" << std::endl;
        std::cout << "Корень 2: " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }

    return 0;
}