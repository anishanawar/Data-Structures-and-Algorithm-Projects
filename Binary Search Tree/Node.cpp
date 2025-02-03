#include <iostream>
#include "Node.h"
#include <string>

using namespace std;

// Constructor for Node
Node::Node(string data) {
    dataString = data;  // Initialize dataString with the given data
    count = 1;          // Initialize count to 1 since this is the first occurrence
    left = 0;           // Initialize left child pointer to null
    right = 0;          // Initialize right child pointer to null
    parent = 0;         // Initialize parent pointer to null
}

// Overloaded assignment operator
Node& Node::operator=(const Node& data) {
    if(this != &data) {
        // Copying data from the right-hand side to the left-hand side
        this->dataString = data.dataString;  // Copy dataString
        this->count = data.count;            // Copy count
    }
    return *this;
}