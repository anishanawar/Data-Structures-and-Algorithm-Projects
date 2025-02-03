#include <iostream>
#include <string>
#include "BSTree.h"
#include "Node.h"

// Constructor: Initialize an empty binary search tree
BSTree::BSTree() {
    root = nullptr; // Initialize the root pointer to nullptr (empty tree)
}

// Helper function: Recursively search for a node with the given data
Node* BSTree::search(const string& data, Node* curr) const {
    if (curr != nullptr) {
        if (data == curr->dataString) {
            return curr; // Node with the desired data found
        } else {
            if (data < curr->dataString) {
                return search(data, curr->left); // Recur on the left subtree
            } else {
                return search(data, curr->right); // Recur on the right subtree
            }
        }
    } else {
        return nullptr; // Node not found
    }
}

// Helper function: Perform in-order traversal and print node data
void BSTree::inOrder(Node* curr) const {
    if (curr != nullptr) {
        inOrder(curr->left); // Recur on the left subtree
        cout << curr->dataString << '(' << curr->count << "), "; // Print node data
        inOrder(curr->right); // Recur on the right subtree
    }
}

// Helper function: Perform post-order traversal and print node data
void BSTree::postOrder(Node* curr) const {
    if (curr != nullptr) {
        postOrder(curr->left); // Recur on the left subtree
        postOrder(curr->right); // Recur on the right subtree
        cout << curr->dataString << '(' << curr->count << "), "; // Print node data
    }
}

// Helper function: Perform pre-order traversal and print node data
void BSTree::preOrder(Node* curr) const {
    if (curr != nullptr) {
        cout << curr->dataString << '(' << curr->count << "), "; // Print node data
        preOrder(curr->left); // Recur on the left subtree
        preOrder(curr->right); // Recur on the right subtree
    }
}

// Helper function: Remove a specific node from the tree
void BSTree::remove(Node* data) {
    Node* curr = data; // Node to be removed
    Node* succ = nullptr; // Successor node

    if (curr->left == nullptr && curr->right == nullptr) {
        // Node has no children
        if (curr->parent != nullptr) {
            // Node is not the root
            if (curr->parent->left == curr) {
                curr->parent->left = nullptr; // Update parent's left pointer
            } else {
                curr->parent->right = nullptr; // Update parent's right pointer
            }
        } else {
            // Node is the root
            root = nullptr; // Set root to nullptr
        }
        delete curr; // Delete the node
    } else if (curr->left != nullptr) {
        // Node has a left child
        succ = curr->left;
        while (succ->right != nullptr) {
            succ = succ->right; // Find the rightmost node in the left subtree
        }
        *curr = *succ; // Copy successor's data to current node
        remove(succ); // Remove the successor node
    } else {
        // Node has a right child
        succ = curr->right;
        while (succ->left != nullptr) {
            succ = succ->left; // Find the leftmost node in the right subtree
        }
        *curr = *succ; // Copy successor's data to current node
        remove(succ); // Remove the successor node
    }
}

// Insert a new node with the given data into the tree
void BSTree::insert(const string& data) {
    Node* curr = root;
    if (search(data)) {
        // Node already exists, update count
        curr = search(data, root);
        curr->count = curr->count + 1;
    } else {
        // Create a new node and insert it into the tree
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode; // Set the new node as the root
        } else {
            while (1) {
                if (data < curr->dataString) {
                    if (curr->left == nullptr) {
                        curr->left = newNode; // Insert into the left subtree
                        newNode->parent = curr; // Set the parent pointer
                        return;
                    } else {
                        curr = curr->left; // Recur on the left subtree
                    }
                } else {
                    if (curr->right == nullptr) {
                        curr->right = newNode; // Insert into the right subtree
                        newNode->parent = curr; // Set the parent pointer
                        return;
                    } else {
                        curr = curr->right; // Recur on the right subtree
                    }
                }
            }
        }
    }
}

// Search for a node with the given data in the tree
bool BSTree::search(const string& data) const {
    return search(data, root) != nullptr; // Return true if node is found, false otherwise
}

// Find the largest node value in the tree
string BSTree::largest() const {
    Node* curr = root;
    if (curr == nullptr) {
        return ""; // Tree is empty, return empty string
    } else {
        while (1) {
            if (curr->right == nullptr) {
                return curr->dataString; // Rightmost node in the tree
            } else {
                curr = curr->right; // Move to the right child
            }
        }
    }
}

// Find the smallest node value in the tree
string BSTree::smallest() const {
    Node* curr = root;
    if (curr == nullptr) {
        return ""; // Tree is empty, return empty string
    } else {
        while (1) {
            if (curr->left == nullptr) {
                return curr->dataString; // Leftmost node in the tree
            } else {
                curr = curr->left; // Move to the left child
            }
        }
    }
}

// Calculate the height of the subtree rooted at a specific node
int BSTree::height(const string& data) const {
    if (!search(data)) {
        return -1; // Node not found, height is -1
    }
    Node* curr = search(data, root);
    Node* currLeft = curr;
    Node* currRight = curr;
    int leftCnt = 0;
    int rightCnt = 0;

    if (curr->left != nullptr) {
        currLeft = currLeft->left; // Move to the left child
        leftCnt++;
        leftCnt = leftCnt + height(currLeft->dataString); // Recur on the left subtree
    }
    if (curr->right != nullptr) {
        currRight = currRight->right; // Move to the right child
        rightCnt++;
        rightCnt = rightCnt + height(currRight->dataString); // Recur on the right subtree
    }
    if (leftCnt >= rightCnt) {
        return leftCnt; // Return the maximum height from left and right subtrees
    } else {
        return rightCnt; // Return the maximum height from left and right subtrees
    }
}

// Remove a node with the given data from the tree
void BSTree::remove(const string& data) {
    if (search(data)) {
        Node* curr = search(data, root);
        if (curr->count > 1) {
            curr->count = curr->count - 1; // Node has more than one instance, decrement count
        } else {
            remove(curr); // Node has only one instance, remove it
        }
    }
}

// Perform pre-order traversal and print node data
void BSTree::preOrder() const {
    preOrder(root); // Start pre-order traversal from the root
    cout << endl; // Move to the next line after traversal
}

// Perform in-order traversal and print node data
void BSTree::inOrder() const {
    inOrder(root); // Start in-order traversal from the root
    cout << endl; // Move to the next line after traversal
}

// Perform post-order traversal and print node data
void BSTree::postOrder() const {
    postOrder(root); // Start post-order traversal from the root
    cout << endl; // Move to the next line after traversal
}