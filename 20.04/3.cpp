#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right])
            return false;
        
        left++;
        right--;
    }
    
    return true;
}

string decimalToBinary(int decimal) {
    string binary = "";
    
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    
    return binary;
}

int main() {
    int sum = 0;
    
    for (int i = 1; i < 1000000; i++) {
        string decimalStr = to_string(i);
        string binaryStr = decimalToBinary(i);
        
        if (isPalindrome(decimalStr) && isPalindrome(binaryStr)) {
            cout << "Palindrome: " << i << endl;
            sum += i;
        }
    }
    
    cout << "Sum of palindromes: " << sum << endl;
    
    return 0;
}