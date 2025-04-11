
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
class Rectangle {
public:
    Point topLeft;
    Point bottomRight;

    Rectangle(Point p1, Point p2) : topLeft(p1), bottomRight(p2) {
        cout << "Прямоугольник создан с верхним левым углом в (" << topLeft.x << ", " << topLeft.y << ") и нижним правым углом в (" << bottomRight.x << ", " << bottomRight.y << ")\n";
    }
};
int main() {
    Point p1;
    p1.move(5, 7);
    p1.print();

    Point p2(3, 4);
    p2.print();

    Point p3 = p2;
    p3.print();

    Circle c1;
    c1.resize(1.5);
    c1.print();

    Circle c2(10, 20, 5.5);
    c2.print();

    return 0;
}
