#include <iostream>
#include <string>

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

int main() {
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);
    
    if (isPalindrome(str)) {
        std::cout << "Строка является палиндромом" << std::endl;
    } else {
        std::cout << "Строка не является палиндромом" << std::endl;
    }
    
    return 0;
}