#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int number) {
    if (number <= 1)
        return false;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

// Функция для вычисления суммы цифр числа
int digitSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Функция для проверки, является ли число числом Харшада
bool isHarshad(int number) {
    int sum = digitSum(number);
    return (number % sum == 0);
}

// Функция для поиска сильных, усекаемых справа простых чисел Харшада
vector<int> findStrongRightTruncatableHarshadNumbers(int limit) {
    vector<int> result;
    vector<int> candidates = {2, 3, 5, 7};  // Начальные кандидаты

    while (!candidates.empty()) {
        int number = candidates.back();
        candidates.pop_back();

        if (number >= limit)
            continue;

        if (isPrime(number))
            result.push_back(number);

        int nextDigit = number % 10;
        for (int i = 0; i <= 9; i++) {
            int nextNumber = number * 10 + i;
            if (isHarshad(nextNumber))
                candidates.push_back(nextNumber);
        }
    }

    return result;
}

int main() {
    cout << 's';
    long long limit = 1e14;
    vector<int> strongRightTruncatableHarshadNumbers = findStrongRightTruncatableHarshadNumbers(limit);

    long long sum = 0;
    cout << 's';
    for (int number : strongRightTruncatableHarshadNumbers){
        cout << number;
        sum += number;
    }
    cout << "Количество сильных, усекаемых справа простых чисел Харшада: " << strongRightTruncatableHarshadNumbers.size() << endl;
    cout << "Сумма сильных, усекаемых справа простых чисел Харшада: " << sum << endl;

    return 0;
}