#include <iostream>
#include <stdexcept>

// Node structure for the linked list
template <class T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// CircularQueue class
template <class T>
class CircularQueue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    CircularQueue();
    ~CircularQueue();
    void enqueue(T element);
    T dequeue();
    bool isEmpty() const;
};

// Constructor
template <class T>
CircularQueue<T>::CircularQueue() : front(nullptr), rear(nullptr) {}

// Destructor
template <class T>
CircularQueue<T>::~CircularQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Check if the circular queue is empty
template <class T>
bool CircularQueue<T>::isEmpty() const {
    return front == nullptr;
}

// Enqueue element
template <class T>
void CircularQueue<T>::enqueue(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front;  // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  // Maintain circular link
    }
}

// Dequeue element
template <class T>
T CircularQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    Node<T>* temp = front;
    T data = front->data;
    if (front == rear) {  // Only one element
        front = rear = nullptr;
    } else {
        front = front->next;
        rear->next = front;  // Maintain circular link
    }
    delete temp;
    return data;
}

// Example usage:
int main() {
    CircularQueue<int> cq;
    cq.enqueue(1);
    cq.enqueue(2);
    std::cout << "Dequeued: " << cq.dequeue() << std::endl;
    cq.enqueue(3);
    std::cout << "Dequeued: " << cq.dequeue() << std::endl;

    return 0;
}
