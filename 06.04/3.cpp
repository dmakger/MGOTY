#include <iostream>
using namespace std;
class Rectangle {
protected:
    double a;
    double b;
public:
    Rectangle(double l, double w) : a(l), b(w) {}
    ~Rectangle() {}
    double calculateArea() {
        return a * b;
    }
};
class Pyramid : public Rectangle {
protected:
    double height;
public:
    Pyramid(double l, double w, double h) : Rectangle(l, w), height(h) {}
    ~Pyramid() {}
    double calculateSurfaceArea() {
        double baseArea = calculateArea();
        double lateralArea = a * sqrt((height * height) + (b * b)) + b * height;
        return baseArea + lateralArea;
    }
    double calculateVolume() {
        return (calculateArea() * height) / 3.0;
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    double a, b, height;
    cout << "Введите длину прямоугольника: ";
    cin >> a;
    cout << "Введите ширину прямоугольника: ";
    cin >> b;
    Rectangle rectangle(a, b);
    cout << "Введите высоту пирамиды: ";
    cin >> height;
    Pyramid pyramid(a, b, height);
    cout << "Площадь прямоугольника: " << rectangle.calculateArea() << endl;
    cout << "Площадь поверхности пирамиды: " << pyramid.calculateSurfaceArea() << endl;
    cout << "Объем пирамиды: " << pyramid.calculateVolume() << endl;
    return 0;
}
