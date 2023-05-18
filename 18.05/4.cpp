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
