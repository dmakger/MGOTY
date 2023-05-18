#include <iostream>
#include <vector>
using namespace std;

int count(int n, int k, vector<int>& memo) {
    if (n == 0) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    int ways = 0;
    for (int i = 1; i <= k && i <= n; i++) {
        ways += count(n - i, k, memo);
    }
    memo[n] = ways;
    return ways;
}
int main() {
    setlocale(LC_ALL, "RU");
    int n, k;
    cout << "Введите кол-во ступенек, а затем максимальное кол-во перепрыгиваемых ступенек\n";
    cin >> k >> n;
    vector<int> memo(n + 1, -1);
    int ways = count(n, k, memo);
    cout << "Количество способов: " << ways << endl;
    return 0;
}
