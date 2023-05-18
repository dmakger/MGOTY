#include <iostream>
#include <vector>

using namespace std;
// Функция для проверки, является ли число простым
bool is_prime(int n){
    if(n<=1) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

// Функция для проверки, является ли число родственником 2
bool is_relative_two(int n){
    // Проверяем, есть ли цифра 2 в числе
    while(n>0){
        if(n%10==2) return false;
        n /= 10;
    }
    // Проверяем, является ли число связным с числом 2
    int count_diff = 0;
    int m = 2;
    while(m<=n){
        if(is_prime(m) && is_prime(n)){
            int diff = 0;
            int a = m, b = n;
            while(a>0 && b>0){
                if(a%10 != b%10) diff++;
                a /= 10;
                b /= 10;
            }
            if(diff == 1) return true;
        }
        // Добавляем одну цифру слева к меньшему числу
        if(m<n) m = m*10+1;
        else n = n*10+1;
    }
    return false;
}

int main(){
    long long n = 10000000;
    long long sum = 0;
    for(int i=2; i<=n; i++){
        if(is_prime(i) && !is_relative_two(i)){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}

// Сначала определяем две функции: is_prime для проверки, является ли число простым, и is_relative_two для проверки, является ли число родственником 2
// В функции is_relative_two сначала проверяем, есть ли цифра 2 в числе, затем проходим по всем парам простых чисел (2, 3), (2, 5), (2, 7), (3, 7), (5, 7), ... и проверяем, являются ли они связными
// Для проверки связности используем переменную diff, которая хранит количество отличающихся цифр между двумя числами
// Если diff равно 1, то числа связны
// В главной функции проходим по всем простым числам до n и суммируем те из них, которые не являются родственниками 2
// Выводим сумму