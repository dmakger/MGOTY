#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
class Circle {
protected:
    float centerX;
    float centerY;
    float radius;

public:
    Circle(float x, float y, float r) : centerX(x), centerY(y), radius(r) {}
    ~Circle() {}
    float calculateArea() {
        return M_PI * radius * radius;
    }
};
class Cone : public Circle {
private:
    float vertexZ;  // Координата Z вершины конуса

public:
    Cone(float x, float y, float r, float z) : Circle(x, y, r), vertexZ(z) {}
    ~Cone() {}
    float calculateSurfaceArea() {
        float slantHeight = sqrt(radius * radius + vertexZ * vertexZ);
        return M_PI * radius * (radius + slantHeight);
    }
    float calculateVolume() {
        return (1.0 / 3.0) * M_PI * radius * radius * vertexZ;
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    float centerX, centerY, radius, vertexZ;
    cout << "Введите координату X центра окружности: ";
    cin >> centerX;
    cout << "Введите координату Y центра окружности: ";
    cin >> centerY;
    cout << "Введите радиус окружности: ";
    cin >> radius;
    Circle circle(centerX, centerY, radius);
    cout << "Площадь окружности: " << circle.calculateArea() << endl;
    cout << "\nВведите координату X вершины конуса: ";
    cin >> centerX;
    cout << "Введите координату Y вершины конуса: ";
    cin >> centerY;
    cout << "Введите радиус основания конуса: ";
    cin >> radius;
    cout << "Введите координату Z вершины конуса: ";
    cin >> vertexZ;
    Cone cone(centerX, centerY, radius, vertexZ);
    cout << "Площадь поверхности конуса: " << cone.calculateSurfaceArea() << endl;
    cout << "Объем конуса: " << cone.calculateVolume() << endl;
    return 0;
}
(проверялось в visual studio)
