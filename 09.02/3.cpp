#include <iostream>

const int N = 3; // Размерность матрицы

void transposeMatrix(int matrix[N][N]) {
    int temp;

    // Транспонирование матрицы
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix[N][N] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    transposeMatrix(matrix);

    // Вывод транспонированной матрицы
    std::cout << "Транспонированная матрица:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}