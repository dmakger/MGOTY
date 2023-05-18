/*
Функция SwapDiagonals принимает вектор A по ссылке. Она выполняет обмен элементами на главной и побочной диагонали с использованием временной переменной temp. В отличие от предыдущего кода, в этом коде используется индекс j вместо i для итерации по столбцам.
Пользователю предлагается ввести размер квадратного массива (n).
Создается двумерный вектор A размером n x n, представляющий квадратный массив.
Пользователю предлагается ввести элементы массива, и они сохраняются в соответствующие ячейки вектора A. Обратите внимание, что индексы i и j использованы в обратном порядке по сравнению с предыдущим кодом. Это означает, что ввод элементов массива происходит по столбцам, а не по строкам.
Вызывается функция SwapDiagonals(A), которая меняет местами элементы на диагоналях вектора A.
Выводится измененный массив на экран с помощью вложенных циклов for, также используя индексы j и i для обращения к элементам вектора A.
Программа завершается.

*/

#include <iostream>
#include <vector>
using namespace std;
void SwapDiagonals(vector<vector<int>>& A) {
   int n = A.size();
   for (int j = 0; j < n; j++) {
      int temp = A[j][j];
      A[j][j] = A[j][n - 1 - j];
      A[j][n - 1 - j] = temp;
   }
}
int main() {
   int n;
   cout << "Введите размер квадратного массива: ";
   cin >> n;

   vector<vector<int>> A(n, vector<int>(n));

   cout << "Введите элементы квадратного массива по его номеру:\n";
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout << "элемент[" << i+1 << "][" << j+1 << "]: ";
         cin >> A[j][i];
      }
   }

   SwapDiagonals(A);

   cout << "Массив после замены диагоналей:\n";
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout << A[j][i] << " ";
      }
      cout << endl;
   }

   return 0;
}
