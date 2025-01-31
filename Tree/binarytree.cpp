#include <iostream>
#include <queue>
using namespace std;

template <class T>
class BinaryTree {
private:
    class Node {
    private:
        T element;
        Node* left;
        Node* right;

    public:
        Node(T element) : element(element), left(nullptr), right(nullptr) {}
        friend class BinaryTree<T>;
    };

    Node* root;

public:
    BinaryTree() : root(nullptr) {}
    
    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(T element) {
        if (root == nullptr) {
            root = new Node(element);
        } else {
            insert(root, element);
        }
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

    void displayLevelOrder() const {
        levelOrder(root);
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

    void insert(Node* node, T element) {
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = new Node(element);
                return;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = new Node(element);
                return;
            } else {
                q.push(temp->right);
            }
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

    void levelOrder(Node* root) const {
        if (!root) return;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            cout << current->element << " ";
            q.pop();

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
};

int main() {
    BinaryTree<int> bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    cout << "In-Order Traversal: ";
    bt.displayInOrder();

    cout << "Pre-Order Traversal: ";
    bt.displayPreOrder();

    cout << "Post-Order Traversal: ";
    bt.displayPostOrder();

    cout << "Level-Order Traversal: ";
    bt.displayLevelOrder();

    return 0;
}
