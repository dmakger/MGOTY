#include <iostream>
using namespace std;
int main() {
    int max_side = 100;
    for (int a = 1; a <= max_side; a++) {
        for (int b = a; b <= max_side; b++) {
            for (int c = b; c <= max_side; c++) {
                if (a * a + b * b == c * c) {
                    cout << a << " " << b << " " << c << endl;
                }
            }
            
        }
        
    }
}
