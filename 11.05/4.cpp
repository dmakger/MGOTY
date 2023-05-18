#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки, является ли текущее размещение безопасным
bool isSafe(vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        // Проверка на угрозу по вертикали и диагонали
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

// Рекурсивная функция для нахождения всех размещений
void findQueenPlacements(vector<int>& queens, int n, int w, int row, int& count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        // Проверка, является ли текущее размещение безопасным для слабых ферзей
        if (col <= w || isSafe(queens, row, col)) {
            queens[row] = col;
            findQueenPlacements(queens, n, w, row + 1, count);
        }
    }
}

// Функция для нахождения числа способов размещения слабых ферзей
int findQueenConfigurations(int n, int w) {
    int count = 0;
    vector<int> queens(n, -1);  // Вектор для хранения позиций ферзей

    findQueenPlacements(queens, n, w, 0, count);

    return count;
}

int main() { 
    int n = 5;
    int w = 0;

    int S_5 = findQueenConfigurations(n, w);
    cout << "S(5) = " << S_5 << endl;

    n = 14;
    int S_14 = findQueenConfigurations(n, w);
    cout << "S(14) = " << S_14 << endl;

    return 0;
}