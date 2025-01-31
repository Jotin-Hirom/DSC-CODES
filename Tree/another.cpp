#include <iostream>
#include <vector>

using namespace std;

// Simple Stack implementation
template <typename T>
class Stack
{
private:
    vector<T> elements; // Internal storage for stack

public:
    void push(const T &value)
    {
        elements.push_back(value); // Add value to the top of the stack
    }

    T pop()
    {
        if (isEmpty())
            throw out_of_range("Stack<>::pop(): empty stack");
        T elem = elements.back(); // Get the top element
        elements.pop_back();      // Remove the top element
        return elem;
    }

    bool isEmpty() const
    {
        return elements.empty(); // Check if the stack is empty
    }
};

// Simple Queue implementation
template <typename T>
class Queue
{
private:
    vector<T> elements; // Internal storage for queue

public:
    void enqueue(const T &value)
    {
        elements.push_back(value); // Add value to the back of the queue
    }

    T dequeue()
    {
        if (isEmpty())
            throw out_of_range("Queue<>::dequeue(): empty queue");
        T elem = elements.front();        // Get the front element
        elements.erase(elements.begin()); // Remove the front element
        return elem;
    }

    bool isEmpty() const
    {
        return elements.empty(); // Check if the queue is empty
    }
};

/**
 * @brief A class representing a Binary Search Tree (BST).
 *
 * This class provides methods for inserting, removing, and traversing nodes
 * in a binary search tree. The tree maintains the BST property, where each
 * node's left subtree contains only nodes with values less than the node's
 * value, and the right subtree contains only nodes with values greater.
 */
template <class T>
class BSTree
{
private:
    // Node class representing each element in the BST
    class Node
    {
    public:
        Node *left;  // Pointer to left child
        T info;      // Data stored in the node
        Node *right; // Pointer to right child

        Node(T ele)
        {
            info = ele;
            left = right = nullptr; // Initialize children to nullptr
        }
    };

    Node *root; // Pointer to the root of the BST

    // Private helper functions

    /**
     * @brief Creates a new node with the given value.
     *
     * @param ele The value to be stored in the new node.
     * @return A pointer to the newly created node.
     */
    Node *makeBSTreeNode(T ele)
    {
        return new Node(ele);
    }

    /**
     * @brief Inserts a new value into the BST.
     *
     * @param root Reference to the root pointer of the current subtree.
     * @param ele The value to be inserted.
     */
    void insert(Node *&root, T ele)
    {
        if (!root) // If the current node is null, insert the new node
        {
            root = makeBSTreeNode(ele);
        }
        else if (ele < root->info) // Go to the left subtree
        {
            insert(root->left, ele);
        }
        else if (ele > root->info) // Go to the right subtree
        {
            insert(root->right, ele);
        }
    }

    /**
     * @brief Removes a value from the BST.
     *
     * @param root Reference to the root pointer of the current subtree.
     * @param ele The value to be removed.
     */
    void remove(Node *&root, T ele)
    {
        if (!root)
            return; // If the current node is null, nothing to remove

        if (ele < root->info) // Go to the left subtree
            remove(root->left, ele);
        else if (ele > root->info) // Go to the right subtree
            remove(root->right, ele);
        else // Node to be deleted found
        {
            if (!root->left) // Node with only right child or no child
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (!root->right) // Node with only left child
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else // Node with two children
            {
                Node *temp = root->right;
                while (temp && temp->left) // Find the inorder successor
                    temp = temp->left;

                root->info = temp->info;         // Copy the inorder successor's content
                remove(root->right, temp->info); // Delete the inorder successor
            }
        }
    }

    /**
     * @brief Performs in-order traversal of the BST.
     *
     * @param root Pointer to the current node.
     */
    void inOrder(Node *root)
    {
        if (root)
        {
            inOrder(root->left);       // Traverse left subtree
            cout << root->info << " "; // Visit node
            inOrder(root->right);      // Traverse right subtree
        }
    }

    /**
     * @brief Performs pre-order traversal of the BST.
     *
     * @param root Pointer to the current node.
     */
    void preOrder(Node *root)
    {
        if (root)
        {
            cout << root->info << " "; // Visit node
            preOrder(root->left);      // Traverse left subtree
            preOrder(root->right);     // Traverse right subtree
        }
    }

    /**
     * @brief Performs post-order traversal of the BST.
     *
     * @param root Pointer to the current node.
     */
    void postOrder(Node *root)
    {
        if (root)
        {
            postOrder(root->left);     // Traverse left subtree
            postOrder(root->right);    // Traverse right subtree
            cout << root->info << " "; // Visit node
        }
    }

public:
    /**
     * @brief Default constructor for BSTree.
     *
     * Initializes the root to nullptr.
     */
    BSTree() : root(nullptr) {}

    /**
     * @brief Destructor for BSTree.
     *
     * Calls the clear method to deallocate memory used by the tree.
     */
    ~BSTree() { clear(root); }

    /**
     * @brief Clears the tree and deallocates memory.
     *
     * @param root Reference to the root pointer of the current subtree.
     */
    void clear(Node *&root)
    {
        if (root)
        {
            clear(root->left);  // Clear left subtree
            clear(root->right); // Clear right subtree
            delete root;        // Delete current node
            root = nullptr;     // Set pointer to null
        }
    }

    /**
     * @brief Copy constructor for BSTree.
     *
     * @param thisTree The BSTree to copy from.
     */
    BSTree(const BSTree<T> &thisTree) : root(nullptr)
    {
        copyTree(root, thisTree.root);
    }

    /**
     * @brief Copies nodes from another tree.
     *
     * @param thisRoot Reference to the root pointer of the current tree.
     * @param otherRoot Pointer to the root of the tree to copy from.
     */
    void copyTree(Node *&thisRoot, Node *otherRoot)
    {
        if (otherRoot)
        {
            thisRoot = makeBSTreeNode(otherRoot->info);  // Create a new node
            copyTree(thisRoot->left, otherRoot->left);   // Copy left subtree
            copyTree(thisRoot->right, otherRoot->right); // Copy right subtree
        }
    }

    /**
     * @brief Assignment operator for BSTree.
     *
     * @param thistree The BSTree to assign from.
     * @return Reference to this BSTree.
     */
    BSTree<T> &operator=(const BSTree<T> &thistree)
    {
        if (this != &thistree) // Avoid self-assignment
        {
            clear(root);                   // Clear current tree
            copyTree(root, thistree.root); // Copy new tree
        }
        return *this;
    }

    /**
     * @brief Inserts a new value into the BST.
     *
     * @param ele The value to be inserted.
     */
    void insert(T ele) { insert(root, ele); }

    /**
     * @brief Removes a value from the BST.
     *
     * @param ele The value to be removed.
     */
    void remove(T ele) { remove(root, ele); }

    /**
     * @brief Performs in-order traversal of the BST.
     *
     * Prints the values in sorted order.
     */
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }

    /**
     * @brief Performs pre-order traversal of the BST.
     *
     * Prints the values in pre-order.
     */
    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    /**
     * @brief Performs post-order traversal of the BST.
     *
     * Prints the values in post-order.
     */
    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }

    /**
     * @brief Performs level-order traversal of the BST.
     *
     * Prints the values level by level.
     */
    void levelOrder(); // Level order implementation would go here

    /**
     * @brief Performs non-recursive pre-order traversal of the BST.
     *
     * Prints the values in pre-order without using recursion.
     */
    void nonRecursivePreOrder(); // Non-recursive pre-order implementation would go here

    /**
     * @brief Performs non-recursive post-order traversal of the BST.
     *
     * Prints the values in post-order without using recursion.
     */
    void nonRecursivePostOrder(); // Non-recursive post-order implementation would go here

    /**
     * @brief Performs non-recursive in-order traversal of the BST.
     *
     * Prints the values in in-order without using recursion.
     */
    void nonRecursiveInOrder(); // Non-recursive in-order implementation would go here
};

// Level order traversal
template <class T>
void BSTree<T>::levelOrder()
{
    if (!root)
        return; // If the tree is empty, do nothing

    Queue<Node *> q; // Assuming Queue is implemented correctly
    q.enqueue(root); // Start with the root node

    while (!q.isEmpty())
    {
        Node *current = q.dequeue();  // Dequeue the front node
        cout << current->info << " "; // Print the node's value

        if (current->left)
            q.enqueue(current->left); // Enqueue left child
        if (current->right)
            q.enqueue(current->right); // Enqueue right child
    }
    cout << endl;
}

// Non-recursive pre-order traversal
template <class T>
void BSTree<T>::nonRecursivePreOrder()
{
    if (!root)
        return; // If the tree is empty, do nothing

    Stack<Node *> s; // Assuming Stack is implemented correctly
    s.push(root);    // Push the root node onto the stack

    while (!s.isEmpty())
    {
        Node *current = s.pop();      // Pop the top node
        cout << current->info << " "; // Print the node's value

        if (current->right)
            s.push(current->right); // Push right child
        if (current->left)
            s.push(current->left); // Push left child
    }
    cout << endl;
}

// Non-recursive in-order traversal
template <class T>
void BSTree<T>::nonRecursiveInOrder()
{
    Stack<Node *> s; // Assuming Stack is implemented correctly
    Node *current = root;

    while (current || !s.isEmpty())
    {
        while (current) // Go to the leftmost node
        {
            s.push(current);         // Push the current node onto the stack
            current = current->left; // Move to left child
        }

        current = s.pop();            // Pop the top node
        cout << current->info << " "; // Print the node's value
        current = current->right;     // Move to right child
    }
    cout << endl;
}

// Non-recursive post-order traversal
template <class T>
void BSTree<T>::nonRecursivePostOrder()
{
    Stack<Node *> s1, s2; // Assuming Stack is implemented correctly
    s1.push(root);        // Start with the root node

    while (!s1.isEmpty())
    {
        Node *current = s1.pop(); // Pop the top node
        s2.push(current);         // Push it onto the second stack

        if (current->left)
            s1.push(current->left); // Push left child
        if (current->right)
            s1.push(current->right); // Push right child
    }

    while (!s2.isEmpty()) // Now print the nodes in post-order
    {
        cout << s2.pop()->info << " "; // Print the node's value
    }
    cout << endl;
}

// Main function to demonstrate BSTree usage
int main()
{
    BSTree<int> tree;

    // Inserting elements into the BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Traversals 
    cout << "In-order traversal: ";
    tree.inOrder(); // Should print: 20 30 40 50 60 70 80

    cout << "Pre-order traversal: ";
    tree.preOrder(); // Should print: 50 30 20 40 70 60 80

    cout << "Post-order traversal: ";
    tree.postOrder(); // Should print: 20 40 30 60 80 70 50

    cout << "Level-order traversal: ";
    tree.levelOrder(); // Should print: 50 30 70 20 40 60 80

    // Non-recursive traversals
    cout << "Non-recursive In-order traversal: ";
    tree.nonRecursiveInOrder();

    cout << "Non-recursive Pre-order traversal: ";
    tree.nonRecursivePreOrder();

    cout << "Non-recursive Post-order traversal: ";
    tree.nonRecursivePostOrder();

    // Removing an element
    cout << "Removing 20\n";
    tree.remove(20);
    cout << "In-order traversal after removing 20: ";
    tree.inOrder(); // Should print: 30 40 50 60 70 80

    return 0;
}
