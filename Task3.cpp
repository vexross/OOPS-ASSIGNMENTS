#include <iostream>
using namespace std;

class Student {
public:
    string name;

    Student() {
        name = "Raj";
        cout << "Default constructor" << endl;
    }

    Student(string n) {
        name = n;
        cout << "Parameterized Constructor" << endl;
    }

    Student(Student &&s) {
        name = s.name;
        cout << "Move Constructor" << endl;
    }

    ~Student() {
        cout << "Destructor" << endl;
    }
};

int main() {
    Student s1;
    cout << "Name: " << s1.name << endl;

    Student s2("Neal");
    cout << "Name: " << s2.name << endl;

    Student s3(s2);
    cout << "Name: " << s3.name << endl;

    Student s4(Student("Sam"));
    cout << "Name: " << s4.name << endl;

    return 0;
}
