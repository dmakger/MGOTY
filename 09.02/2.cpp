#include <iostream>
#include <vector>

int main() {
    const int SIZE = 7;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6, 7},
        {2, 3, 4, 5, 6, 7, 8},
        {3, 4, 5, 6, 7, 8, 9},
        {4, 5, 6, 7, 8, 9, 10},
        {5, 6, 7, 8, 9, 10, 11},
        {6, 7, 8, 9, 10, 11, 12},
        {7, 8, 9, 10, 11, 12, 13}
    };

    std::vector<int> columnIndices;

    for (int j = 0; j < SIZE; j++) {
        bool isIncreasing = true;

        for (int i = 0; i < SIZE - 1; i++) {
            if (matrix[i][j] >= matrix[i + 1][j]) {
                isIncreasing = false;
                break;
            }
        }

        if (isIncreasing) {
            columnIndices.push_back(j);
        }
    }

    std::cout << "Столбцы с возрастающей последовательностью элементов: ";
    for (int index : columnIndices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}