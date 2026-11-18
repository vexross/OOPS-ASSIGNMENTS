#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    float r;
public:
    Circle(float radius) : r(radius) {}
    float area() {
        return 3.14f * r * r;
    }
};

class Rectangle : public Shape {
    float w, h;
public:
    Rectangle(float width, float height) : w(width), h(height) {}
    float area() {
        return w * h;
    }
};

class Triangle : public Shape {
    float b, h;
public:
    Triangle(float base, float height) : b(base), h(height) {}
    float area() {
        return 0.5f * b * h;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(3.0f);
    shapes[1] = new Rectangle(4.0f, 5.0f);
    shapes[2] = new Triangle(3.0f, 6.0f);

    cout << "Circle Area: " << shapes[0]->area() << endl;
    cout << "Rectangle Area: " << shapes[1]->area() << endl;
    cout << "Triangle Area: " << shapes[2]->area() << endl;

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
