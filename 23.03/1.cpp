#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Passenger {
private:
    vector<double> weights;
public:
    void addWeight(double weight) {
        weights.push_back(weight);
    }
    double getTotalWeight() const {
        double totalWeight = 0.0;
        for (double weight : weights) {
            totalWeight += weight;
        }
        return totalWeight;
    }
    int getNumberOfItems() const {
        return weights.size();
    }
    double getAverageWeight() const {
        if (weights.empty()) {
            return 0.0;
        }
        return getTotalWeight() / getNumberOfItems();
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    int numberOfPassengers;
    cout << "Введите количество пассажиров: ";
    cin >> numberOfPassengers;
    vector<Passenger> passengers;
    for (int i = 0; i < numberOfPassengers; i++) {
        int numberOfItems;
        cout << "Введите количество вещей пассажира " << (i + 1) << ": ";
        cin >> numberOfItems;
        Passenger passenger;
        for (int j = 0; j < numberOfItems; j++) {
            double weight;
            cout << "Введите вес вещи " << (j + 1) << ": ";
            cin >> weight;
            passenger.addWeight(weight);
        }
        passengers.push_back(passenger);
    }
    cout << "Общий вес багажа каждого пассажира:" << endl;
    for (const Passenger& passenger : passengers) {
        cout << "Вес багажа пассажира: " << passenger.getTotalWeight() << " кг" << endl;
    }
    double totalWeight = 0.0;
    int totalItems = 0;
    for (const Passenger& passenger : passengers) {
        totalWeight += passenger.getTotalWeight();
        totalItems += passenger.getNumberOfItems();
    }
    double averageWeight = totalWeight / totalItems;
    cout << "Пассажиры с близким средним весом вещей:" << endl;
    for (const Passenger& passenger : passengers) {
        double passengerAverageWeight = passenger.getAverageWeight();
        if (abs(passengerAverageWeight - averageWeight) <= 0.3) {
            cout << "Вес багажа пассажира: " << passenger.getTotalWeight() << " кг" << endl;
        }
    }
    int passengersWithMoreThanThreeItems = 0;
    for (const Passenger& passenger : passengers) {
        if (passenger.getNumberOfItems() > 3) {
            passengersWithMoreThanThreeItems++;
        }
    }
    cout << "Количество пассажиров с более чем тремя вещами: " << passengersWithMoreThanThreeItems << endl;
    return 0;
}
