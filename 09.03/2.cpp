#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    long long n;
    cout << "Введите верхнюю грань\n";
    cin >> n;
    if (n < 2) {
        cout << "n должно быть >= 2" << endl;
        return 0;
    }
    bool* prime = new bool[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p <= sqrt(n); p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
    delete[] prime;
    return 0;
}
