#include <iostream>
#include <stdexcept>

template <class T, int MAX_SIZE>
class Dequeue
{
private:
    T item[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Dequeue();  // Constructor
    ~Dequeue(); // Destructor
    void insertFront(T element);
    void insertRear(T element);
    T removeFront();
    T removeRear();
    bool isFull() const;
    bool isEmpty() const;
};

// Constructor
template <class T, int MAX_SIZE>
Dequeue<T, MAX_SIZE>::Dequeue() : front(0), rear(-1), count(0) {}

// Destructor
template <class T, int MAX_SIZE>
Dequeue<T, MAX_SIZE>::~Dequeue() { delete[] items; }

// Check if the Dequeue is full
template <class T, int MAX_SIZE>
bool Dequeue<T, MAX_SIZE>::isFull() const
{
    return count == MAX_SIZE;
}

// Check if the Dequeue is empty
template <class T, int MAX_SIZE>
bool Dequeue<T, MAX_SIZE>::isEmpty() const
{
    return count == 0;
}

// Insert element at the front
template <class T, int MAX_SIZE>
void Dequeue<T, MAX_SIZE>::insertFront(T element)
{
    if (isFull())
    {
        throw std::overflow_error("Dequeue is full");
    }
    front = (front - 1 + MAX_SIZE) % MAX_SIZE; // Circular decrement
    item[front] = element;
    count++;
}

// Insert element at the rear
template <class T, int MAX_SIZE>
void Dequeue<T, MAX_SIZE>::insertRear(T element)
{
    if (isFull())
    {
        throw std::overflow_error("Dequeue is full");
    }
    rear = (rear + 1) % MAX_SIZE; // Circular increment
    item[rear] = element;
    count++;
}

// Remove element from the front
template <class T, int MAX_SIZE>
T Dequeue<T, MAX_SIZE>::removeFront()
{
    if (isEmpty())
    {
        throw std::underflow_error("Dequeue is empty");
    }
    T removedItem = item[front];
    front = (front + 1) % MAX_SIZE; // Circular increment
    count--;
    return removedItem;
}

// Remove element from the rear
template <class T, int MAX_SIZE>
T Dequeue<T, MAX_SIZE>::removeRear()
{
    if (isEmpty())
    {
        throw std::underflow_error("Dequeue is empty");
    }
    T removedItem = item[rear];
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE; // Circular decrement
    count--;
    return removedItem;
}

// Example usage:
int main()
{
    Dequeue<int, 5> dq;
    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(0);
    std::cout << "Removed from front: " << dq.removeFront() << std::endl;
    std::cout << "Removed from rear: " << dq.removeRear() << std::endl;

    return 0;
}
