#ifndef __AVLTREE_H__  // Header guard to prevent multiple inclusions of the header file
#define __AVLTREE_H__

#include "Node.h"  // Include the header file for the Node class

// Declaration of the AVLTree class
class AVLTree
{
  private:
    Node* root = nullptr;  // Pointer to the root of the AVL tree
  public:
    int balanceFactor(Node*) const;  // Function to calculate the balance factor of a node
    void insert(const string &);  // Function to insert a new key into the AVL tree
    void printBalanceFactors() const;  // Function to print balance factors for all nodes in the AVL tree
  private:
    void updateHeight(Node*);  // Function to update the height of a node based on its children's heights
    bool setChild(Node*, string, Node*);  // Function to set the child (left or right) of a node
    bool replaceChild(Node*, Node*, Node*);  // Function to replace a child of a node with a new child
    void rotateRight(Node*);  // Function to rotate the AVL tree to the right
    void rotateLeft(Node*);  // Function to rotate the AVL tree to the left
    void rebalance(Node*);  // Function to rebalance the AVL tree after an insertion
    void recurBalanceFactors(Node*) const;  // Recursive function to print balance factors for nodes in the AVL tree
};

#endif // __AVLTREE_H__  // End of the header file and header guard