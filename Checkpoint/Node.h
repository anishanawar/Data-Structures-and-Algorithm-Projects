#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <iostream>

using namespace std;

// Declaration of the Node class
class Node
{
    friend class Tree; // Allowing Tree class to access private members of Node

private:
    // Private constructor to prevent external instantiation
    Node();

    // Constructor with a string parameter to initialize the Node with a string value
    Node(const string &);

    // Private member variables representing small and large strings in the Node
    string small;
    string large;

    // Pointers to left, middle, right child Nodes, and the parent Node
    Node *left;
    Node *middle;
    Node *right;
    Node *parent;

    // Private member function to check if the Node is full (both small and large strings occupied)
    bool isFull();
};

#endif