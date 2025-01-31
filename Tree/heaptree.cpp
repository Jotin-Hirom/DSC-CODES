
#include <iostream>
#include <vector>
using namespace std;

// Base class for Heap
class Heap {
protected:
    vector<int> heap;
    virtual void heapifyUp(int index) = 0;
    virtual void heapifyDown(int index) = 0;

public:
    void insert(int element) {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot() {
        if (heap.size() > 1) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        } else if (heap.size() == 1) {
            heap.pop_back();
        }
    }

    void displayHeap() const {
        for (int element : heap)
            cout << element << " ";
        cout << endl;
    }
};

// Min-Heap class derived from Heap
class MinHeap : public Heap {
private:
    void heapifyUp(int index) override {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) override {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    int getMin() const {
        return heap.empty() ? -1 : heap[0];
    }
};

// Max-Heap class derived from Heap
class MaxHeap : public Heap {
private:
    void heapifyUp(int index) override {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) override {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    int getMax() const {
        return heap.empty() ? -1 : heap[0];
    }
};

// Main function to test both heaps
int main() {
    MinHeap minHeap;
    MaxHeap maxHeap;

    // Inserting elements into Min-Heap
    minHeap.insert(15);
    minHeap.insert(10);
    minHeap.insert(30);
    minHeap.insert(5);
    minHeap.insert(20);

    cout << "Min-Heap elements: ";
    minHeap.displayHeap();
    cout << "Minimum element: " << minHeap.getMin() << endl;

    minHeap.deleteRoot();
    cout << "Min-Heap after deleting root: ";
    minHeap.displayHeap();

    // Inserting elements into Max-Heap
    maxHeap.insert(15);
    maxHeap.insert(10);
    maxHeap.insert(30);
    maxHeap.insert(5);
    maxHeap.insert(20);

    cout << "\nMax-Heap elements: ";
    maxHeap.displayHeap();
    cout << "Maximum element: " << maxHeap.getMax() << endl;

    maxHeap.deleteRoot();
    cout << "Max-Heap after deleting root: ";
    maxHeap.displayHeap();

    return 0;
}


// ### Explanation of Code:

// 1. **Heap Base Class**:
//    - Contains the common methods for both heaps, such as `insert`, `deleteRoot`, and `displayHeap`.

// 2. **Min-Heap Class (Derived from Heap)**:
//    - Implements `heapifyUp` to maintain the Min-Heap property by bubbling up smaller elements.
//    - Implements `heapifyDown` to maintain the Min-Heap property when deleting the root by sinking down larger elements.
//    - `getMin` returns the minimum element, which is the root.

// 3. **Max-Heap Class (Derived from Heap)**:
//    - Implements `heapifyUp` to maintain the Max-Heap property by bubbling up larger elements.
//    - Implements `heapifyDown` to maintain the Max-Heap property when deleting the root by sinking down smaller elements.
//    - `getMax` returns the maximum element, which is the root.

// 4. **Main Function**:
//    - Inserts elements into both the Min-Heap and Max-Heap, displays the heap contents, and demonstrates deletion of the root element in each heap.