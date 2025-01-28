#include <iostream>

template <class T>
class DoublyLinkedList {
    // Inner class Node
    class Node {
    public: 
        T data;           // Data stored in the node
        Node *next;      // Pointer to the next node
        Node *prev;      // Pointer to the previous node

        Node(T data) : data(data), next(nullptr), prev(nullptr) {} // Constructor
    };

    Node *head; // Pointer to the first node

public:
    DoublyLinkedList() : head(nullptr) {} // Constructor initializes head to nullptr

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp; // Free memory for each node
        }
    }

    // Insert a new node at the beginning of the list
    void insertAtStart(T data) {
        Node* newNode = new Node(data);
        if (head != nullptr) {
            newNode->next = head; // New node points to current head
            head->prev = newNode; // Previous head points back to new node
        }
        head = newNode; // Update head to new node
    }

    // Insert a new node at the end of the list
    void insertAtEnd(T data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode; // If the list is empty, set head to new node
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; // Traverse to the last node
        }
        current->next = newNode; // Link the last node to the new node
        newNode->prev = current; // Link new node back to the last node
        return;
    }

    // Remove a node with a specific value
    void remove(T data) {
        if (head == nullptr) return; // List is empty
        Node* current = head;
        while (current != nullptr && current->data != data) {
            current = current->next; // Find the node to be removed
        }
        if (current == nullptr) return; // Node not found
        if (current->prev != nullptr) {
            current->prev->next = current->next; // Bypass the node to be deleted
        } else {
            head = current->next; // Node to be removed is the head
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev; // Link the next node back
        }
        delete current; // Free memory
    }

    // Search for a node with a specific value
    bool search(T data) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return true; // Data found
            }
            current = current->next; // Move to the next node
        }
        return false; // Data not found
    }

    // Display the list 
    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " <-> "; // Display with arrows
            current = current->next;
        }
        std::cout << "nullptr" << std::endl; // Indicate end of the list
    }
};

// Main function to demonstrate functionality for Doubly Linked List
int main() {
    DoublyLinkedList<int> myList;

    myList.insertAtStart(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtStart(5);

    std::cout << "Doubly Linked List: ";
    myList.display(); // Output: 5 <-> 10 <-> 20 <-> 30 <-> nullptr

    myList.remove(20); // Remove node with value 20
    std::cout << "After removing 20: ";
    myList.display(); // Output: 5 <-> 10 <-> 30 <-> nullptr

    // Search for a node
    if (myList.search(10)) {
        std::cout << "Node with value 10 found." << std::endl;
    } else {
        std::cout << "Node with value 10 not found." << std::endl;
    }

    return 0;
}
