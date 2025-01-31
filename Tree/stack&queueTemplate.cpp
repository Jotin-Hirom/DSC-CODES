#include <iostream>
using namespace std;

// Template of Stack
template <class T>
class Stack
{
private:
    class StackNode
    {
    private:
        T element;
        StackNode *next;

    public:
        StackNode() : next(nullptr) {};
        friend class Stack<T>;
    };
    StackNode *top;
    int sizeOfStack;

public:
    Stack() : top(nullptr), sizeOfStack(0) {};
    void push(T element); // Insertion
    T pop();              // Deletion
    void print() const;   // Displaying
};

// Template of Queue
template <class T>
class Queue
{
private:
    class QueueNode
    {
    private:
        T element;
        QueueNode *next;

    public:
        QueueNode() : next(nullptr) {};
        friend class Queue<T>;
    };
    QueueNode *front;
    QueueNode *rear;
    int sizeOfStack;

public:
    Queue() : front(nullptr), rear(nullptr), sizeOfStack(0) {};
    void enqueue(T element); // Insertion
    void dequeue();          // Deletion
    void print();            // Displaying
};

template <class T>
void Stack<T>::push(T element)
{
}

template <class T>
T Stack<T>::pop()
{
    return T();
}

template <class T>
void Stack<T>::print() const
{
}

template <class T>
void Queue<T>::enqueue(T element)
{
}

template <class T>
void Queue<T>::dequeue()
{
}

template <class T>
void Queue<T>::print()
{
}

int main()
{
    return 0;
}