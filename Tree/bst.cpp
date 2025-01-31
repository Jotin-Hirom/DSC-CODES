#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree {
private:
    class Node {
    private:
        T element;
        Node* left;
        Node* right;

    public:
        Node(T element) : element(element), left(nullptr), right(nullptr) {}
        friend class BinarySearchTree<T>;
    };

    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(T element) {
        root = insert(root, element);
    }

    void remove(T element) {
        root = remove(root, element);
    }

    bool search(T element) const {
        return search(root, element);
    }

    void displayInOrder() const {
        inOrder(root);
        cout << endl;
    }

    void displayPreOrder() const {
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() const {
        postOrder(root);
        cout << endl;
    }

private:
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    Node* insert(Node* node, T element) {
        if (node == nullptr) {
            return new Node(element);
        }
        if (element < node->element) {
            node->left = insert(node->left, element);
        } else if (element > node->element) {
            node->right = insert(node->right, element);
        }
        return node;
    }

    Node* remove(Node* node, T element) {
        if (node == nullptr) {
            return node;
        }

        if (element < node->element) {
            node->left = remove(node->left, element);
        } else if (element > node->element) {
            node->right = remove(node->right, element);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->element = temp->element;
            node->right = remove(node->right, temp->element);
        }
        return node;
    }

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

    void inOrder(Node* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->element << " ";
            inOrder(node->right);
        }
    }

    void preOrder(Node* node) const {
        if (node != nullptr) {
            cout << node->element << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) const {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->element << " ";
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);

    cout << "In-Order Traversal: ";
    bst.displayInOrder();

    cout << "Pre-Order Traversal: ";
    bst.displayPreOrder();

    cout << "Post-Order Traversal: ";
    bst.displayPostOrder();

    int searchValue = 15;
    if (bst.search(searchValue)) {
        cout << "Element " << searchValue << " found in the BST." << endl;
    } else {
        cout << "Element " << searchValue << " not found in the BST." << endl;
    }

    bst.remove(10);
    cout << "In-Order Traversal after deletion: ";
    bst.displayInOrder();

    return 0;
}
