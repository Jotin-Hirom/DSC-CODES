#include <iostream>

template <class T>
class ListLinked
{ 
    // Inner class Node
    class Node
    {
    private:
        T data;     // Data stored in the node
        Node *next; // Pointer to the next node

    public:
        Node(T data) : data(data), next(nullptr) {} // Constructor
        friend class ListLinked<T>;                 // Allow ListLinked to access private members
    };

    Node *head; // Pointer to the first node in the list

public:
    ListLinked() : head(nullptr) {} // Constructor initializes head to nullptr

    // Destructor to free memory
    ~ListLinked()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp; // Free memory for each node
        }
    }

    // Insert a new node at the beginning of the list
    void insertAtStart(T data)
    {
        Node *newNode = new Node(data);
        newNode->next = head; // New node points to the current head
        head = newNode;       // Update head to the new node
    }

    // Insert a new node at the end of the list
    void insertAtEnd(T data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode; // If the list is empty, set head to new node
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        { // Traverse to the last node
            current = current->next;
        }
        current->next = newNode; // Link the last node to the new node
    }

    // Insert a new node after a specific value
    void insertAfter(T existingData, T newData)
    {
        // int k=1;
        Node *current = head;
        while (current != nullptr && current->data != existingData)//(current->next != nullptr && k<p)
        {
            //k++;
            current = current->next; // Find the node with existingData
        }
        // if (k!=p) cout<<"Position is not defined."<<endl; return;
        if (current != nullptr)
        { // If the node exists
            Node *newNode = new Node(newData);
            newNode->next = current->next; // Link new node to the next node
            current->next = newNode;       // Link current node to the new node
        }
        else
        {
            std::cout << "Node with value " << existingData << " not found." << std::endl;
        }
    }
    // Remove a node with a specific value
    void remove(T data)
    {
        if (head == nullptr)
            return; // List is empty
        if (head->data == data)
        { // Node to be removed is the head
            Node *temp = head;
            head = head->next; // Move head to the next node
            delete temp;       // Free the memory
            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->data != data)
        {
            current = current->next; // Find the node to be removed
        }
        if (current->next != nullptr)
        { // Node found
            Node *temp = current->next;
            current->next = current->next->next; // Bypass the node to be deleted
            delete temp;                         // Free memory
        }
        else
        {
            std::cout << "Node with value " << data << " not found." << std::endl;
        }
    }

    // Search for a node with a specific value
    bool search(T data) const
    { 
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return true; // Data found
            }
            current = current->next; // Move to the next node
        }
        return false; // Data not found
    }

    // Display the list
    void display() const
    {
        std::cout<<head;
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl; // Indicate end of the list
    }
};

// Main function to demonstrate functionality
int main()
{
    ListLinked<int> myList;

    myList.insertAtStart(10);
    myList.insertAtStart(20);
    myList.insertAtEnd(30);
    myList.insertAtEnd(40);
    myList.insertAfter(20, 25); // Insert 25 after 20
    myList.insertAtStart(24);

    std::cout << "List after insertions: ";
    myList.display(); // Output: 20 -> 25 -> 10 -> 30 -> 40 -> nullptr

    myList.remove(25); // Remove node with value 25
    std::cout << "List after removing 25: ";
    myList.display(); // Output: 20 -> 10 -> 30 -> 40 -> nullptr

    // Search for a node
    int valueToSearch = 30;
    if (myList.search(valueToSearch))
    {
        std::cout << "Node with value " << valueToSearch << " found." << std::endl;
    }
    else
    {
        std::cout << "Node with value " << valueToSearch << " not found." << std::endl;
    }

    // Try to search for a non-existent node
    valueToSearch = 100;
    if (myList.search(valueToSearch))
    {
        std::cout << "Node with value " << valueToSearch << " found." << std::endl;
    }
    else
    {
        std::cout << "Node with value " << valueToSearch << " not found." << std::endl;
    }

    return 0;
}
