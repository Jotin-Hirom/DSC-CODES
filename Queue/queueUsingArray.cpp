#include <iostream>
#include <stdexcept>

template <class T, int MAX_SIZE>
class Queue
{
private: 
    T item[MAX_SIZE]; // Array to store queue elements
    int front;        // Index for the front of the queue
    int rear;         // Index for the rear of the queue
    int count;        // Count of elements in the queue

public:
    Queue();                 // Constructor
    ~Queue();                // Destructor
    void enqueue(T element); // Add element to the queue
    T dequeue();             // Remove element from the queue
    bool isFull() const;     // Check if the queue is full
    bool isEmpty() const;    // Check if the queue is empty
};

// Constructor
template <class T, int MAX_SIZE>
Queue<T, MAX_SIZE>::Queue() : front(0), rear(-1), count(0) {}

// Destructor
template <class T, int MAX_SIZE>
Queue<T, MAX_SIZE>::~Queue() {}

// Check if the queue is full
template <class T, int MAX_SIZE>
bool Queue<T, MAX_SIZE>::isFull() const
{
    return count == MAX_SIZE;
}

// Check if the queue is empty
template <class T, int MAX_SIZE>
bool Queue<T, MAX_SIZE>::isEmpty() const
{
    return count == 0;
}

// Add element to the queue
template <class T, int MAX_SIZE>
void Queue<T, MAX_SIZE>::enqueue(T element)
{
    if (isFull())
    {
        throw std::overflow_error("Queue is full");
    }
    rear = (rear + 1) % MAX_SIZE; // Circular increment for the rear
    item[rear] = element;         // Add the element to the queue
    count++;                      // Increment the count of elements
}

// Remove element from the queue
template <class T, int MAX_SIZE>
T Queue<T, MAX_SIZE>::dequeue()
{
    if (isEmpty())
    {
        throw std::underflow_error("Queue is empty");
    }
    T removedItem = item[front];    // Get the element at the front
    front = (front + 1) % MAX_SIZE; // Circular increment for the front
    count--;                        // Decrement the count of elements
    return removedItem;             // Return the dequeued element
}

// Example usage:
int main()
{
    Queue<int, 5> q; // Create a queue of integers with a max size of 5

    // Enqueue elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Add more elements
    q.enqueue(4);
    q.enqueue(5);

    // Dequeue and print elements
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Output: 1
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Output: 2
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Output: 3
    // Dequeue and print elements
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Output: 4
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Output: 5
    q.enqueue(5);

    return 0;
}
