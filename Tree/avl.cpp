#include <iostream>
using namespace std;

template <class T>
class AVLTree {
private:
    class Node {
    private:
        T element;
        Node* left;
        Node* right;
        int height;
        
    public:
        Node(T element) : element(element), left(nullptr), right(nullptr), height(1) {};
        friend class AVLTree<T>;
    };

    Node* root;

public:
    AVLTree() : root(nullptr) {};

    ~AVLTree() {
        destroyTree(root);
    }

    void insert(T element) {
        root = insert(root, element);
    }

    void remove(T element) {
        root = remove(root, element);
    }

    bool search(T element) {
        return search(root, element);
    }

    void displayInOrder() const {
        inOrder(root);
        cout << endl;
    }

private:
    // Destroy AVL tree
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Insert element into AVL tree and balance
    Node* insert(Node* node, T element) {
        if (node == nullptr) {
            return new Node(element);
        }

        if (element < node->element) {
            node->left = insert(node->left, element);
        } else if (element > node->element) {
            node->right = insert(node->right, element);
        } else {
            return node;  // Duplicate elements not allowed
        }

        updateHeight(node);
        return balance(node);
    }

    // Remove element from AVL tree and balance
    Node* remove(Node* node, T element) {
        if (node == nullptr) {
            return node;
        }

        if (element < node->element) {
            node->left = remove(node->left, element);
        } else if (element > node->element) {
            node->right = remove(node->right, element);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = minValueNode(node->right);
                node->element = temp->element;
                node->right = remove(node->right, temp->element);
            }
        }

        if (node == nullptr) return node;

        updateHeight(node);
        return balance(node);
    }

    // Search for element in AVL tree
    bool search(Node* node, T element) const {
        if (node == nullptr) {
            return false;
        }

        if (element == node->element) {
            return true;
        } else if (element < node->element) {
            return search(node->left, element);
        } else {
            return search(node->right, element);
        }
    }

    // In-order traversal
    void inOrder(Node* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->element << " ";
            inOrder(node->right);
        }
    }

    // Update height of a node
    int height(Node* node) const {
        return node ? node->height : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    int getBalanceFactor(Node* node) const {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Perform right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    // Perform left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    // Balance the AVL tree
    Node* balance(Node* node) {
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            return rightRotate(node);
        }
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
            return leftRotate(node);
        }
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find the node with the minimum value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    AVLTree<int> avl;
    
    // Insert elements
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "In-order traversal after insertions: ";
    avl.displayInOrder();

    // Delete elements
    avl.remove(20);
    cout << "In-order traversal after deleting 20: ";
    avl.displayInOrder();

    // Search for elements
    int searchElement = 30;
    if (avl.search(searchElement)) {
        cout << "Element " << searchElement << " found in AVL tree." << endl;
    } else {
        cout << "Element " << searchElement << " not found in AVL tree." << endl;
    }

    return 0;
}
