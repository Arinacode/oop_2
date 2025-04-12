#include <iostream>
#include <string>

using namespace std;

class Point {
public:
    int x, y;

    // Конструктор по умолчанию
    Point() : x(0), y(0) {
        cout << "Point()\n";
    }

    // Конструктор с параметрами
    Point(int xVal, int yVal) : x(xVal), y(yVal) {
        cout << "Point(" << x << ", " << y << ")\n";
    }

    // Конструктор копирования
    Point(const Point& p) : x(p.x), y(p.y) {
        cout << "Point(" << x << ", " << y << ")\n";
    }

    // Метод перемещения
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // Метод вывода точки
    void print() const {
        cout << "(" << x << ", " << y << ")\n";
    }

    // Деструктор
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

// композиция(включает в себя объекты поинт  как части себя)
class Rectangle {
public:
    Point topLeft;
    Point bottomRight;

    Rectangle(Point p1, Point p2) : topLeft(p1), bottomRight(p2) {
        cout << " верхний левый угол в (" << topLeft.x << ", " << topLeft.y
            << ") нижний правый угол в (" << bottomRight.x << ", " << bottomRight.y << ")\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Point p1;//создание точки по умолчанию и ее сдвиг
    p1.move(5, 7);
    p1.print();

    Point p2(3, 4);//создание точки с координатами
    p2.print();

    Point p3 = p2; // Копируем p2 в p3
    p3.print();

    Circle c1;//создание круга по умолчанию
    c1.resize(1.5);
    c1.print();

    Circle c2(10, 20, 5.5);//круг с параметрами
    c2.print();

    // Динамическое создание и удаление объекта
    Point* p = new Point(5, 7);  // Динамическое создание через указатель
    delete p;                    

    // Создание объекта с композицией(прямоугольник)
    Rectangle r(Point(0, 0), Point(5, 5));
    return 0;
}
