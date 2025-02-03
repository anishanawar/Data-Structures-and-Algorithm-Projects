#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"
#include <string>

using namespace std;

class BSTree {

private:
    Node *root;

private:
    Node * search(const string &, Node *) const;  // Helper function for searching a node
    void inOrder(Node *) const;  // Helper function for in-order traversal
    void postOrder(Node *) const;  // Helper function for post-order traversal
    void preOrder(Node *) const;  // Helper function for pre-order traversal
    void remove(Node *);  // Helper function for removing a node

public:
    BSTree();  // Constructor for initializing the tree
    void insert(const string &);  // Function to insert a new string into the tree
    bool search(const string &) const;  // Function to search for a string in the tree
    string largest( ) const;  // Function to find the largest string in the tree
    string smallest( ) const;  // Function to find the smallest string in the tree
    int height(const string &) const;  // Function to calculate the height of a subtree
    void remove(const string &);  // Function to remove a string from the tree

    void preOrder( ) const;  // Function for pre-order traversal of the tree
    void inOrder( ) const;  // Function for in-order traversal of the tree
    void postOrder( ) const;  // Function for post-order traversal of the tree
};

#endif