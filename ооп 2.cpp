
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
    
};
