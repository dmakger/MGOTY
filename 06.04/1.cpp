#include <iostream>
#include <cmath>
using namespace std;
class Triangle {
protected:
    double a, b, c;
public:
    Triangle(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {
        cout << "Создан треугольник со сторонами: " << a << ", " << b << ", " << c << endl;
    }
    ~Triangle() {
        cout << "Уничтожен треугольник со сторонами: " << a << ", " << b << ", " << c << endl;
    }
    double getPerimeter() {
        return a + b + c;
    }
    double getArea() {
        double p = getPerimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
class DerivedTriangle : public Triangle {
public:
    DerivedTriangle(double a1, double b1, double c1) : Triangle(a1, b1, c1) {}
    void printAngles() {
        double angle1 = acos((b * b + c * c - a * a) / (2.0 * b * c));
        double angle2 = acos((a * a + c * c - b * b) / (2.0 * a * c));
        double angle3 = acos((a * a + b * b - c * c) / (2.0 * a * b));
        cout << "Углы треугольника: " << angle1 << ", " << angle2 << ", " << angle3 << " (в радианах)" << endl;
    }
    double getHeight() {
        double p = getPerimeter() / 2.0;
        double area = getArea();
        double height = (2.0 * area) / a;
        return height;
    }
    double getAreaByBaseAndHeight(double base, double height) {
        return (base * height) / 2.0;
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    double a1, b1, c1;
    cout << "Введите стороны треугольника: ";
    cin >> a1 >> b1 >> c1;
    Triangle triangle(a1, b1, c1);
    cout << "Периметр треугольника: " << triangle.getPerimeter() << endl;
    cout << "Площадь треугольника: " << triangle.getArea() << endl;
    DerivedTriangle derivedTriangle(a1, b1, c1);
    derivedTriangle.printAngles();
    cout << "Высота треугольника: " << derivedTriangle.getHeight() << endl;
    double base, height;
    cout << "Введите основание и высоту для расчета площади: ";
    cin >> base >> height;
    cout << "Площадь треугольника по основанию и высоте: " << derivedTriangle.getAreaByBaseAndHeight(base, height) << endl;
    return 0;
}
