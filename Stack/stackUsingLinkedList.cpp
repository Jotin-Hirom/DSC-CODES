#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:  
    // Forward declaration of Node class
    class Node
    { 
    public:
        T data;     // Data of generic type T
        Node *next; // Pointer to the next node

        Node(T value) : data(value), next(nullptr) {}
    };

    Node *top;        // Pointer to the top of the stack
    int currentSize;  // To keep track of the number of elements in the stack

public:
    // Constructor
    Stack() : top(nullptr), currentSize(0) {}

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push element onto the stack
    void push(const T& element) {
        Node *newNode = new Node(element);
        newNode->next = top;
        top = newNode;
        currentSize++;
    }

    // Pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop element." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        currentSize--;
    }

    // Peek at the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Stack is empty. Cannot peek.");
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Return the current size of the stack
    int size() const {
        return currentSize;
    }
};

int main() {
    Stack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.peek() << endl;
    cout << "Stack size: " << intStack.size() << endl;

    intStack.pop();
    cout << "Top element after pop: " << intStack.peek() << endl;
    cout << "Stack size after pop: " << intStack.size() << endl;

    return 0;
}
