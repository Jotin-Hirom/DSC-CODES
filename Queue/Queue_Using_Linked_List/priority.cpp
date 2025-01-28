#include <iostream>
#include <stdexcept>

// Node structure for the linked list
template <class T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// PriorityQueue class
template <class T>
class PriorityQueue {
private:
    Node<T>* front;

public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(T element);
    T dequeue();
    bool isEmpty() const;
};

// Constructor
template <class T>
PriorityQueue<T>::PriorityQueue() : front(nullptr) {}

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Check if the priority queue is empty
template <class T>
bool PriorityQueue<T>::isEmpty() const {
    return front == nullptr;
}

// Enqueue element based on priority (in sorted order)
template <class T>
void PriorityQueue<T>::enqueue(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (isEmpty() || front->data > element) {
        newNode->next = front;
        front = newNode;
    } else {
        Node<T>* temp = front;
        while (temp->next != nullptr && temp->next->data <= element) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Dequeue element with the highest priority (smallest element)
template <class T>
T PriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty");
    }
    Node<T>* temp = front;
    T data = front->data;
    front = front->next;
    delete temp;
    return data;
}

// Example usage:
int main() {
    PriorityQueue<int> pq;
    pq.enqueue(4);
    pq.enqueue(2);
    pq.enqueue(5);
    std::cout << "Dequeued (priority): " << pq.dequeue() << std::endl;
    pq.enqueue(1);
    std::cout << "Dequeued (priority): " << pq.dequeue() << std::endl;

    return 0;
}
