#include "AVLTree.h"  // Include the header file containing the AVLTree class definition

#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::max;

// Function to calculate the balance factor of a node in the AVL tree
int AVLTree::balanceFactor(Node *node) const
{
    int leftHeight = -1;
    if (node->left)
    {
        leftHeight = node->left->height;
    }

    int rightHeight = -1;
    if (node->right)
    {
        rightHeight = node->right->height;
    }

    return leftHeight - rightHeight;
}

// Function to update the height of a node based on its children's heights
void AVLTree::updateHeight(Node *node)
{
    int leftHeight = -1;
    if (node->left)
    {
        leftHeight = node->left->height;
    }

    int rightHeight = -1;
    if (node->right)
    {
        rightHeight = node->right->height;
    }

    node->height = max(leftHeight, rightHeight) + 1;
}

// Function to set the child of a node (left or right)
bool AVLTree::setChild(Node *parent, string whichChild, Node *child)
{
    if (whichChild != "left" && whichChild != "right")
    {
        return false;  // Invalid input for whichChild
    }

    // Set the child pointer of the parent to the new child
    if (whichChild == "left")
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    // Update the parent pointer of the new child
    if (child)
    {
        child->parent = parent;
    }

    // Update the height of the parent node
    updateHeight(parent);
    return true;
}

// Function to replace a child of a node with a new child
bool AVLTree::replaceChild(Node *parent, Node *currentChild, Node *newChild)
{
    if (parent->left == currentChild)
    {
        return setChild(parent, "left", newChild);
    }
    else if (parent->right == currentChild)
    {
        return setChild(parent, "right", newChild);
    }

    return false;  // The specified currentChild is not a child of the parent
}

// Rotate the AVL tree to the right
void AVLTree::rotateRight(Node *node)
{
    Node* leftRightChild = node->left->right;

    // Replace the current node with its left child
    if (node->parent)
    {
        replaceChild(node->parent, node, node->left);
    }
    else // node is root
    {
        root = node->left;
        root->parent = nullptr;
    }

    // Update child pointers to perform the rotation
    setChild(node->left, "right", node);
    setChild(node, "left", leftRightChild);
}

// Rotate the AVL tree to the left
void AVLTree::rotateLeft(Node *node)
{
    Node* rightLeftChild = node->right->left;

    // Replace the current node with its right child
    if (node->parent)
    {
        replaceChild(node->parent, node, node->right);
    }
    else // node is root
    {
        root = node->right;
        root->parent = nullptr;
    }

    // Update child pointers to perform the rotation
    setChild(node->right, "left", node);
    setChild(node, "right", rightLeftChild);
}

// Rebalance the AVL tree after an insertion
void AVLTree::rebalance(Node *node)
{
    updateHeight(node);  // Update the height of the current node

    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->right) == 1)
        {
            // Double rotation case.
            rotateRight(node->right);
        }

        rotateLeft(node);
    }
    else if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->left) == -1)
        {
            // Double rotation case.
            rotateLeft(node->left);
        }

        rotateRight(node);
    }
}

// Insert a new key into the AVL tree
void AVLTree::insert(const string &str)
{
    Node* curr = root;

    // Traverse the tree to find the correct position for the new key
    while (curr)
    {
        if (curr->key > str)
        {
            curr = curr->left;
        }
        else if (curr->key < str)
        {
            curr = curr->right;
        }
        else
        {
            return;  // Key already exists in the tree
        }
    }

    Node* node = new Node(str);  // Create a new node with the given key

    if (!root)
    {
        root = node;
        node->parent = nullptr;
        return;
    }

    Node* cur = root;
    while (cur)
    {
        // Insert the new node as the left child if its key is smaller, otherwise, insert as the right child
        if (node->key < cur->key)
        {
            if (!cur->left)
            {
                cur->left = node;
                node->parent = cur;
                cur = nullptr;
            }
            else
            {
                cur = cur->left;
            }
        }
        else
        {
            if (!cur->right)
            {
                cur->right = node;
                node->parent = cur;
                cur = nullptr;
            }
            else
            {
                cur = cur->right;
            }
        }
    }

    node = node->parent;

    // Rebalance the tree starting from the newly inserted node
    while (node)
    {
        rebalance(node);
        node = node->parent;
    }
}

// Print balance factors for all nodes in the AVL tree
void AVLTree::printBalanceFactors() const
{
    recurBalanceFactors(root);
    cout << endl;
}

// Recursive function to print balance factors for nodes in the AVL tree
void AVLTree::recurBalanceFactors(Node *node) const
{
    if (node)
    {
        recurBalanceFactors(node->left);
        cout << node->key << "(" << balanceFactor(node) << "), ";
        recurBalanceFactors(node->right);
    }
}