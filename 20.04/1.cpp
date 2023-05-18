#include <iostream>
#include <vector>
#include <string>

void findCombinations(std::vector<std::string>& expressions, std::string current, int target, int num, int diff) {
    if (num == 10) {
        if (target == 100) {
            expressions.push_back(current);
        }
        return;
    }

    // Вставляем знак '+'
    findCombinations(expressions, current + "+" + std::to_string(num), target + num, num + 1, num);

    // Вставляем знак '-'
    findCombinations(expressions, current + "-" + std::to_string(num), target - num, num + 1, -num);

    // Не вставляем знак
    findCombinations(expressions, current + std::to_string(num), target - diff + diff * 10 + num, num + 1, diff * 10 + num);
}

int main() {
    std::vector<std::string> expressions;
    findCombinations(expressions, "1", 1, 2, 1);

    std::cout << "Все возможные комбинации, равные 100:\n";
    for (const auto& expression : expressions) {
        std::cout << expression << "\n";
    }

    return 0;
}