#include <iostream>
#include <vector>

using namespace std;

// Функция для подсчета количества делителей числа
int countDivisors(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

// Функция для подсчета f(n)
int countNumbersWithEightDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (countDivisors(i) == 8) {
            count++;
        }
    }
    return count;
}

int main() {
    int f_100 = countNumbersWithEightDivisors(100);
    int f_1000 = countNumbersWithEightDivisors(1000);
    int f_106 = countNumbersWithEightDivisors(1000000);
    long long f_1012 = countNumbersWithEightDivisors(1000000000000);

    cout << "f(100) = " << f_100 << endl;
    cout << "f(1000) = " << f_1000 << endl;
    cout << "f(10^6) = " << f_106 << endl;
    cout << "f(10^12) = " << f_1012 << endl;

    return 0;
}