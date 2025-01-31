// Implementing a B*-tree in C++ is a bit more involved due to the complexity of the B*-tree structure,
//  which is a variation of the B-tree designed to keep nodes fuller and reduce splits by redistributing
//  elements between sibling nodes before splitting. This example code will create a basic B*-tree
//  with insertion and search functionality.

// A B*-tree generally:

// Has nodes that store multiple keys.
// Attempts to fill nodes as much as possible before splitting.
// Balances itself to maintain sorted order and enable efficient insertion and search operations.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// B* Tree Node structure
template <class T>
class BStarTreeNode {
private:
    vector<T> keys;       // Keys in the node
    vector<BStarTreeNode*> children; // Children pointers
    bool leaf;            // True if leaf node
    int maxKeys;          // Maximum number of keys per node

public:
    BStarTreeNode(int degree, bool isLeaf) : leaf(isLeaf), maxKeys(2 * degree) {}

    // Insert a key into the subtree rooted at this node
    void insertNonFull(T key);
    // Split a full child node
    void splitChild(int i, BStarTreeNode* child);
    // Search for a key in the subtree rooted at this node
    bool search(T key) const;
    
    friend class BStarTree<T>;
};

// B* Tree structure
template <class T>
class BStarTree {
private:
    BStarTreeNode<T>* root; // Pointer to root node
    int degree;             // Minimum degree (defines range for number of keys)

public:
    BStarTree(int degree) : root(nullptr), degree(degree) {}

    // Insert a new key in the B* Tree
    void insert(T key);
    // Search for a key in the B* Tree
    bool search(T key) const {
        return root == nullptr ? false : root->search(key);
    }
};

// Insert a new key in the B* Tree
template <class T>
void BStarTree<T>::insert(T key) {
    if (root == nullptr) {
        // Allocate root if tree is empty
        root = new BStarTreeNode<T>(degree, true);
        root->keys.push_back(key);
    } else {
        // If root is full, grow the tree in height
        if (root->keys.size() == 2 * degree - 1) {
            BStarTreeNode<T>* newRoot = new BStarTreeNode<T>(degree, false);
            newRoot->children.push_back(root);
            newRoot->splitChild(0, root);

            int i = (newRoot->keys[0] < key) ? 1 : 0;
            newRoot->children[i]->insertNonFull(key);

            root = newRoot;
        } else {
            root->insertNonFull(key);
        }
    }
}

// Insert a key into a non-full node
template <class T>
void BStarTreeNode<T>::insertNonFull(T key) {
    int i = keys.size() - 1;

    if (leaf) {
        // Insert in sorted order in leaf
        keys.push_back(key);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        // Find child for insertion
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        i++;

        if (children[i]->keys.size() == 2 * degree - 1) {
            splitChild(i, children[i]);

            if (keys[i] < key) {
                i++;
            }
        }
        children[i]->insertNonFull(key);
    }
}

// Split the child node of a full parent node
template <class T>
void BStarTreeNode<T>::splitChild(int i, BStarTreeNode* child) {
    int midIndex = degree - 1;
    BStarTreeNode* newNode = new BStarTreeNode(child->maxKeys / 2, child->leaf);

    // Move half of the child's keys to new node
    for (int j = 0; j < degree - 1; j++) {
        newNode->keys.push_back(child->keys[j + degree]);
    }
    if (!child->leaf) {
        for (int j = 0; j < degree; j++) {
            newNode->children.push_back(child->children[j + degree]);
        }
    }

    // Resize the child node
    child->keys.resize(midIndex);
    child->children.resize(degree);

    // Insert the middle key to the parent
    keys.insert(keys.begin() + i, child->keys[midIndex]);
    children.insert(children.begin() + i + 1, newNode);
}

// Search for a key in the B* Tree node
template <class T>
bool BStarTreeNode<T>::search(T key) const {
    int i = 0;
    while (i < keys.size() && key > keys[i]) {
        i++;
    }

    if (i < keys.size() && keys[i] == key) {
        return true;
    }

    if (leaf) {
        return false;
    }

    return children[i]->search(key);
}

int main() {
    BStarTree<int> bstarTree(3);  // Degree 3 B* tree

    bstarTree.insert(10);
    bstarTree.insert(20);
    bstarTree.insert(5);
    bstarTree.insert(6);
    bstarTree.insert(12);
    bstarTree.insert(30);
    bstarTree.insert(7);
    bstarTree.insert(17);

    cout << "Searching for 10: " << (bstarTree.search(10) ? "Found" : "Not Found") << endl;
    cout << "Searching for 15: " << (bstarTree.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
