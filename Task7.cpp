#include <iostream>
using namespace std;

template <typename T, int CAPACITY = 100>
class Stack {
private:
    T data[CAPACITY];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(T value) {
        if (topIndex >= CAPACITY - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        data[++topIndex] = value;
    }

    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }
        topIndex--;
    }

    T top() {
        if (topIndex < 0) {
            cout << "Stack is empty!\n";
            return T();
        }
        return data[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    Stack<int, 5> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    cout << "Integer Stack Top: " << intStack.top() << endl;
    intStack.pop();
    cout << "After pop, Integer Stack Top: " << intStack.top() << "\n\n";

    Stack<float, 5> floatStack;
    floatStack.push(3.14f);
    floatStack.push(2.718f);
    cout << "Float Stack Top: " << floatStack.top() << "\n\n";

    Stack<const char*, 5> stringStack;
    stringStack.push("Hello");
    stringStack.push("Templates");
    cout << "String Stack Top: " << stringStack.top() << endl;
    stringStack.pop();
    std::cout << "After pop, String Stack Top: " << stringStack.top() << endl;

    return 0;
}
