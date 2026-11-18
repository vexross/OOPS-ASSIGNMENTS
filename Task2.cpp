#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string Name;
protected:
    int DOB;
public:
    Student(string name, int dob) : Name(name), DOB(dob) {}
    void display() {
        cout << "Name: " << Name << ", DOB: " << DOB << endl;
    }
    friend void showGrade(class Grade g); 
};
class Grade : public Student {
private:
    int Marks;
public:
    Grade(string name, int dob, int marks) : Student(name, dob), Marks(marks) {}
    friend void showGrade(Grade g);
};
void showGrade(Grade g) {
    g.display();
    cout << "Marks: " << g.Marks << endl;
    cout << "DOB(Protected access): " << g.DOB << endl;
}

int main() {
    Grade myDetails("Raj", 2007, 85);
    showGrade(myDetails);
    return 0;
}
