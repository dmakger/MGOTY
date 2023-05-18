#include <iostream>
using namespace std;
class Card {
public:
    string suit;
    string rank;
    Card(string suit, string rank) {
        this->suit = suit;
        this->rank = rank;
    }
    void display() {
        cout << rank << " " << suit << endl;
    }
};
class TrumpCard : public Card {
public:
    Card secondCard;
    string trump;
    TrumpCard(string suit1, string rank1, string suit2, string rank2, string trump)
        : Card(suit1, rank1), secondCard(suit2, rank2) {
        this->trump = trump;
    }
    bool covers() {
        if (suit == secondCard.suit) {
            return rank > secondCard.rank;
        }
        else if (suit == trump) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    Card card1("Черви", "7");
    Card card2("Пики", "Туз");
    card1.display();
    card2.display();
    TrumpCard trumpCard("Бубны", "10", "Бубны", "2", "Бубны");
    bool isCovered = trumpCard.covers();
    if (isCovered) {
        cout << "Первая карта кроет вторую карту с учетом козыря" << endl;
    }
    else {
        cout << "Первая карта не кроет вторую карту с учетом козыря" << endl;
    }
    return 0;
}
