#include <iostream>
#include <stdexcept>

// Node structure for the linked list
template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// Dequeue class
template <class T>
class Dequeue {
private:
    Node<T>* front;
    Node<T>* rear;
 
public:
    Dequeue();
    ~Dequeue();
    void insertFront(T element);
    void insertRear(T element);
    T removeFront();
    T removeRear();
    bool isEmpty() const;
};

// Constructor
template <class T>
Dequeue<T>::Dequeue() : front(nullptr), rear(nullptr) {}

// Destructor
template <class T>
Dequeue<T>::~Dequeue() {
    while (!isEmpty()) {
        removeFront();
    }
}

// Check if the dequeue is empty
template <class T>
bool Dequeue<T>::isEmpty() const {
    return front == nullptr;
}

// Insert element at the front
template <class T>
void Dequeue<T>::insertFront(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

// Insert element at the rear
template <class T>
void Dequeue<T>::insertRear(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
}

// Remove element from the front
template <class T>
T Dequeue<T>::removeFront() {
    if (isEmpty()) {
        throw std::underflow_error("Dequeue is empty");
    }
    Node<T>* temp = front;
    T data = front->data;
    front = front->next;
    if (front != nullptr) {
        front->prev = nullptr;
    } else {
        rear = nullptr;  // The queue is now empty
    }
    delete temp;
    return data;
}

// Remove element from the rear
template <class T>
T Dequeue<T>::removeRear() {
    if (isEmpty()) {
        throw std::underflow_error("Dequeue is empty");
    }
    Node<T>* temp = rear;
    T data = rear->data;
    rear = rear->prev;
    if (rear != nullptr) {
        rear->next = nullptr;
    } else {
        front = nullptr;  // The queue is now empty
    }
    delete temp;
    return data;
}

// Example usage:
int main() {
    Dequeue<int> dq;
    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(0);
    std::cout << "Removed from front: " << dq.removeFront() << std::endl;
    std::cout << "Removed from rear: " << dq.removeRear() << std::endl;

    return 0;
}
