#include "Node.h"

// Constructor for Node class without arguments
Node::Node() : left(nullptr), middle(nullptr), right(nullptr), parent(nullptr) {}

// Constructor for Node class with a small string argument
Node::Node(const string &small) : small(small), large(""), left(nullptr), middle(nullptr), right(nullptr), parent(nullptr) {}

// Function to check if the node is full (both small and large strings are filled)
bool Node::isFull(){
    // if large is full (aka both strings are full), return true
    return !large.empty(); 
}