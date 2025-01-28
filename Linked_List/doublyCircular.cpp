#include <iostream>

template <class T>
class DoublyCircularLinkedList {
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
    DoublyCircularLinkedList() : head(nullptr) {} // Constructor initializes head to nullptr

    // Destructor to free memory
    ~DoublyCircularLinkedList() {
        if (head == nullptr) return;
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current; // Free memory for each node
            current = nextNode;
        } while (current != head);
    }

    // Insert a new node at the beginning of the list
    void insertAtStart(T data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode; // If the list is empty, set head to new node
            newNode->next = head; // Point to itself
            newNode->prev = head; // Point to itself
        } else {
            Node* last = head->prev; // Get the last node
            newNode->next = head;     // New node points to head
            newNode->prev = last;     // New node points to last
            last->next = newNode;     // Last node points to new node
            head->prev = newNode;     // Head points back to new node
            head = newNode;           // Update head to new node
        }
    }

    // Insert a new node at the end of the list
    void insertAtEnd(T data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode; // If the list is empty, set head to new node
            newNode->next = head; // Point to itself
            newNode->prev = head; // Point to itself
        } else {
            Node* last = head->prev; // Get the last node
            newNode->next = head;     // New node points to head
            newNode->prev = last;     // New node points to last
            last->next = newNode;     // Last node points to new node
            head->prev = newNode;     // Head points back to new node
        }
    }

    // Remove a node with a specific value
    void remove(T data) {
        if (head == nullptr) return; // List is empty
        Node *current = head;
        do {
            if (current->data == data) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next; // Bypass the node to be deleted
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev; // Link the next node back
                }
                if (current == head) {
                    if (current->next == head) {
                        head = nullptr; // If only one node was present
                    } else {
                        head = current->next; // Update head
                    }
                }
                delete current; // Free memory
                return;
            }
            current = current->next; // Move to the next node
        } while (current != head);
    }

    // Search for a node with a specific value
    bool search(T data) const {
        if (head == nullptr) return false; // List is empty
        Node* current = head;
        do {
            if (current->data == data) {
                return true; // Data found
            }
            current = current->next; // Move to the next node
        } while (current != head);
        return false; // Data not found
    }

    // Display the list
    void display() const {
        if (head == nullptr) return; // List is empty
        Node* current = head;
        do {
            std::cout << current->data << " <-> "; // Display with arrows
            current = current->next;
        } while (current != head);
        std::cout << "(back to head: " << head->data << ")" << std::endl; // Indicate circular nature
    }
};

// Main function to demonstrate functionality for Doubly Circular Linked List
int main() {
    DoublyCircularLinkedList<int> myList;

    myList.insertAtStart(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtStart(5);

    std::cout << "Doubly Circular Linked List: ";
    myList.display(); // Output: 5 <-> 10 <-> 20 <-> 30 <-> (back to head: 5)

    myList.remove(20); // Remove node with value 20
    std::cout << "After removing 20: ";
    myList.display(); // Output: 5 <-> 10 <-> 30 <-> (back to head: 5)

    // Search for a node
    if (myList.search(10)) {
        std::cout << "Node with value 10 found." << std::endl;
    } else {
        std::cout << "Node with value 10 not found." << std::endl;
    }

    return 0;
}
