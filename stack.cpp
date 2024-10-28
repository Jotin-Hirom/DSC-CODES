#include <iostream>
using namespace std;

template <class T, int MAX_SIZE>
class Stack { 
private:
    T arr[MAX_SIZE];  // Array of type T to hold stack elements
    int top;          // Index to track the top element

public:
    // Constructor
    Stack() : top(-1) {}

    // Push element onto the stack
    bool push(const T& element) {
        if (isFull()) {
            cout << "Stack overflow. Cannot push " << element << endl;
            return false;
        }
        arr[++top] = element;
        return true;
    } 

    // Pop element from the stack
    bool pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop element." << endl;
            return false;
        }
        --top;
        return true;
    }

    // Peek at the top element without removing it
    T peek() const {
        if (!isEmpty()) {
            return arr[top];
        } else {
            throw out_of_range("Stack is empty. Cannot peek.");
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // Return the current size of the stack
    int size() const {
        return top + 1;
    }
};

int main() {
    Stack<int, 5> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.peek() << endl;
    cout << "Stack size: " << intStack.size() << endl;

    intStack.pop();
    cout << "Top element after pop: " << intStack.peek() << endl;
    
    return 0;
}
