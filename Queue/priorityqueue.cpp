#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <class T>
class PriorityQueue {
private:
    std::vector<T> queue;

public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(T element);
    T dequeue();
    bool isEmpty() const;
};

// Constructor
template <class T>
PriorityQueue<T>::PriorityQueue() {}

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue() {}

// Check if the priority queue is empty
template <class T>
bool PriorityQueue<T>::isEmpty() const {
    return queue.empty();
}

// Add element to the priority queue
template <class T>
void PriorityQueue<T>::enqueue(T element) {
    queue.push_back(element);    // Add element at the end
    std::sort(queue.begin(), queue.end());  // Sort the queue based on priority
}

// Remove element with the highest priority (smallest element)
template <class T>
T PriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty");
    }
    T highestPriority = queue.front();  // Element with the highest priority
    queue.erase(queue.begin());         // Remove the element from the queue
    return highestPriority;
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
