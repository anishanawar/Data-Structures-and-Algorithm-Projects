#ifndef _NODE_H_
#define _NODE_H_

#include <string>
using namespace std;

class Node {
    friend class BSTree;  // Allowing BSTree class to access private members of Node

private:
    string dataString;    // Data stored in the node
    int count;            // Count of occurrences of the data
    Node* left;           // Pointer to the left child node
    Node* right;          // Pointer to the right child node
    Node* parent;         // Pointer to the parent node

public:
    Node(string);         // Constructor: initializes a node with given data
    Node& operator=(const Node& data);  // Overloaded assignment operator for copying nodes
};

#endif