#ifndef __NODE_H__  // Header guard to prevent multiple inclusions of the header file
#define __NODE_H__

#include <string>  // Include the header file for string

using std::string;  // Use the string type from the standard library

// Definition of the Node structure
struct Node
{
    Node(string);  // Constructor to create a node with the given key
    int height;  // Height of the node in the AVL tree
    string key;  // Key value stored in the node
    Node* left;  // Pointer to the left child of the node
    Node* right;  // Pointer to the right child of the node
    Node* parent;  // Pointer to the parent of the node
};

#endif // __NODE_H__  // End of the header file and header guard