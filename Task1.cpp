#include <iostream>
using namespace std;
int main() {
    int age=19;
    float height=5.7;
    char grade='A';
    bool isStudent=true;
    const int MAX_MARKS=100;
    int Stud_age;
    int a=10,b=3;
    cout<<"Age: " <<age<<",Height: " <<height<< ",Grade: " <<grade<<endl;
    cout<<"Is Student:"<<isStudent<<",Max Marks:"<<MAX_MARKS<<endl;
    cout<<"Sum: " << a+b << ", Diff: " << a-b << ", Product: " <<a*b << endl;
    cout<<"Quotient: " << a/b << ", Remainder: " << a%b << ", a>b: " << (a > b) << endl;
    cout<<"Enter your age: ";
    cin>>Stud_age;
    cout<<"You entered:"<<Stud_age<<endl;
    return 0;
}
