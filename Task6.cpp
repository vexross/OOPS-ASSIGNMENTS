#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    void display() {
        cout << real << "+" << imag << "i\n";
    }

    void display(const char* msg) {
        cout << msg << real << "+" << imag << "i\n";
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }
};

int main() {
    Complex c1(2, 3), c2(4, 5);
    c1.display("First: ");
    Complex c3 = c1 + c2;
    c3.display("Sum: ");
    return 0;
}
