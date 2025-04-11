
#include <iostream>
#include <string>
using namespace std;
class Point {
public:
    int x, y;
    Point() : x(0), y(0) {
        cout << "Point()\n";
    }
    Point() : x(0), y(0) {
        cout << "Point()\n";
    }
    Point(int xVal, int yVal) : x(xVal), y(yVal) {
        cout << "Point(" << x << ", " << y << ")\n";
    }
    Point(const Point& p) : x(p.x), y(p.y) {
        cout << "Point(" << x << ", " << y << ")\n";
    }
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    void print() const {
        cout << "(" << x << ", " << y << ")\n";
    }
    ~Point() {
        cout << "~Point() " << "(" << x << ", " << y << ")\n";
    }

};
class Circle : public Point {
public:
    double radius;

    // Конструктор по умолчанию
    Circle() : Point(), radius(1.0) {
        cout << "Circle()\n";
    }

    // Конструктор с параметрами
    Circle(int x, int y, double r) : Point(x, y), radius(r) {
        cout << "Circle(" << x << ", " << y << ", " << radius << ")\n";
    }

    // Метод изменения радиуса
    void resize(double factor) {
        radius *= factor;
    }

    // Метод вывода круга
    void print() const {
        Point::print();
        cout << "radius = " << radius << endl;
    }

    // Деструктор
    ~Circle() {
        cout << "~Circle() " << "radius = " << radius << endl;
    }
};