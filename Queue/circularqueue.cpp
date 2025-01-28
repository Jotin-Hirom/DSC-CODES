#include <iostream>
#include <stdexcept>

template <class T, int MAX_SIZE>
class CircularQueue {
private:
    T item[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    CircularQueue();
    ~CircularQueue();
    void enqueue(T element);
    T dequeue();
    bool isFull() const;
    bool isEmpty() const;
};

// Constructor
template <class T, int MAX_SIZE>
CircularQueue<T, MAX_SIZE>::CircularQueue() : front(0), rear(-1), count(0) {}

// Destructor
template <class T, int MAX_SIZE>
CircularQueue<T, MAX_SIZE>::~CircularQueue() {}

// Check if the queue is full
template <class T, int MAX_SIZE>
bool CircularQueue<T, MAX_SIZE>::isFull() const {
    return count == MAX_SIZE;
}

// Check if the queue is empty
template <class T, int MAX_SIZE>
bool CircularQueue<T, MAX_SIZE>::isEmpty() const {
    return count == 0;
}

// Add element to the queue
template <class T, int MAX_SIZE>
void CircularQueue<T, MAX_SIZE>::enqueue(T element) {
    if (isFull()) {
        throw std::overflow_error("Queue is full");
    }
    rear = (rear + 1) % MAX_SIZE;  // Circular increment
    item[rear] = element;
    count++;
}

// Remove element from the queue
template <class T, int MAX_SIZE>
T CircularQueue<T, MAX_SIZE>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    T removedItem = item[front];
    front = (front + 1) % MAX_SIZE;  // Circular increment
    count--;
    return removedItem;
}

// Example usage:
int main() {
    CircularQueue<int, 5> cq;
    cq.enqueue(1);
    cq.enqueue(2);
    std::cout << "Dequeued: " << cq.dequeue() << std::endl;
    cq.enqueue(3);
    std::cout << "Dequeued: " << cq.dequeue() << std::endl;

    return 0;
}
