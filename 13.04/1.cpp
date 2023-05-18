#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Children {
private:
    std::string firstName;
    std::string lastName;
    int age;
public:
    void inputData() {
        std::cout << "Введите имя: ";
        std::cin >> firstName;
        std::cout << "Введите фамилию: ";
        std::cin >> lastName;
        std::cout << "Введите возраст: ";
        std::cin >> age;
    }
    void displayData() {
        std::cout << "Имя: " << firstName << std::endl;
        std::cout << "Фамилия: " << lastName << std::endl;
        std::cout << "Возраст: " << age << std::endl;
    }
};
class AddressBook {
private:
    struct Contact {
        std::string firstName;
        std::string lastName;
        std::string birthDate;
        std::string phoneNumber;
    };
    std::vector<Contact> contacts;
public:
    void addContact() {
        Contact newContact;
        std::cout << "Введите имя: ";
        std::cin >> newContact.firstName;
        std::cout << "Введите фамилию: ";
        std::cin >> newContact.lastName;
        std::cout << "Введите дату рождения (dd/mm/yyyy): ";
        std::cin >> newContact.birthDate;
        std::cout << "Введите телефонный номер: ";
        std::cin >> newContact.phoneNumber;
        contacts.push_back(newContact);
    }
    void displayContacts() {
        std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
            return a.lastName < b.lastName;
            });
        for (int i = 0; i < contacts.size(); i++) {
            std::cout << i + 1 << ". " << contacts[i].lastName << ": " << contacts[i].phoneNumber << std::endl;
        }
    }
    void displayBirthdaysInMonth(const std::string& month) {
        std::cout << "Родися в " << month << ":" << std::endl;
        for (const auto& contact : contacts) {
            std::string contactMonth = contact.birthDate.substr(3, 2);
            if (contactMonth == month) {
                std::cout << "- " << contact.firstName << " " << contact.lastName << ": " << contact.birthDate.substr(0, 2) << std::endl;
            }
        }
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    AddressBook addressBook;
    addressBook.addContact();
    addressBook.addContact();
    std::cout << "Контакт в адрессной книге:" << std::endl;
    addressBook.displayContacts();
    std::string searchMonth;
    std::cout << "Кого поздравить в этом месяце: ";
    std::cin >> searchMonth;
    addressBook.displayBirthdaysInMonth(searchMonth);
    return 0;
}
