#include <iostream>
using namespace std;

class Person {
protected:
    int id;
public:
    Person(int i) : id(i) {}
    virtual void show() {
        cout << "ID: " << id << "\n";
    }
};

class Student : public Person {
protected:
    int marks;
public:
    Student(int i, int m) : Person(i), marks(m) {}
    void show() override {
        cout << "Student ID: " << id << ", Marks: " << marks << "\n";
    }
};

class GraduateStudent : public Student {
    const char* thesis;
public:
    GraduateStudent(int i, int m, const char* t) : Student(i, m), thesis(t) {}
    void show() override {
        cout << "Grad Student ID: " << id << ", Marks: " << marks << ", Thesis: " << thesis << "\n";
    }
};

int main() {
    GraduateStudent g(101, 92, "AI");
    g.show();
    return 0;
}
