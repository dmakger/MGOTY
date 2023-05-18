#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Flight {
    string flightNumber;
    int availableSeats;
};
int main() {
    setlocale(LC_ALL, "RU");
    string flightNumber;
    cout << "Введите номер рейса: ";
    cin >> flightNumber;
    ifstream inputFile("flights.txt");
    if (!inputFile) {
        cerr << "Не удалось открыть файл flights.txt" << endl;
        return 1;
    }
    Flight flight;
    bool flightFound = false;
    while (inputFile >> flight.flightNumber >> flight.availableSeats) {
        if (flight.flightNumber == flightNumber) {
            flightFound = true;
            break;
        }
    }
    inputFile.close();
    if (flightFound) {
        cout << "Свободных мест на рейсе " << flight.flightNumber << ": " << flight.availableSeats << endl;
    }
    else {
        cout << "Рейс с номером " << flightNumber << " не найден." << endl;
    }
    return 0;
}
