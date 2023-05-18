#include <iostream>

// Функция для вычисления суммы элементов массива с использованием for-цикла
int sumWithForLoop(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Функция для вычисления суммы элементов массива с использованием while-цикла
int sumWithWhileLoop(int arr[], int size) {
    int sum = 0;
    int i = 0;
    while (i < size) {
        sum += arr[i];
        i++;
    }
    return sum;
}

// Вспомогательная рекурсивная функция для вычисления суммы элементов массива
int recursiveSum(int arr[], int size, int index, int sum) {
    if (index >= size) {
        return sum;
    }
    sum += arr[index];
    return recursiveSum(arr, size, index + 1, sum);
}

// Функция для вычисления суммы элементов массива с использованием рекурсии
int sumWithRecursion(int arr[], int size) {
    return recursiveSum(arr, size, 0, 0);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sumForLoop = sumWithForLoop(arr, size);
    std::cout << "Сумма с использованием for-цикла: " << sumForLoop << std::endl;

    int sumWhileLoop = sumWithWhileLoop(arr, size);
    std::cout << "Сумма с использованием while-цикла: " << sumWhileLoop << std::endl;

    int sumRecursion = sumWithRecursion(arr, size);
    std::cout << "Сумма с использованием рекурсии: " << sumRecursion << std::endl;

    return 0;
}