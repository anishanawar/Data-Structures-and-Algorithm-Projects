#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Define a structure for a node in a circular linked list
struct Node {
    string payload; // The data or payload stored in the node
    Node* next;      // Pointer to the next node in the list
};

// Function to create a new node with the given payload
Node* newNode(string payload) {
    Node* node = new Node; // Allocate memory for a new node
    node->payload = payload; // Set the payload of the new node
    node->next = nullptr; // Initialize the next pointer to null
    return node;
}

// Function to load the game by creating a circular linked list with the given names
Node* loadGame(int n, vector<string> names) {
    Node* head = nullptr; // Pointer to the head of the circular linked list
    Node* prev = nullptr; // Pointer to the previous node in the list
    string name;

    // Loop through the names vector to create a circular linked list
    for (int i = 0; i < n; ++i) {
        name = names.at(i);
        if (head == nullptr) {
            head = newNode(name); // Create the first node if the list is empty
            prev = head;
        } else {
            prev->next = newNode(name); // Add a new node to the list
            prev = prev->next; // Move the previous pointer to the newly added node
        }
    }

    // Make the circular connection by linking the last node to the head
    if (prev != nullptr) {
        prev->next = head;
    }
    return head;
}

// Function to print the circular linked list starting from the given node
void print(Node* start) {
    Node* curr = start;
    while (curr != nullptr) {
        cout << curr->payload << endl; // Output the payload of the current node
        curr = curr->next;
        if (curr == start) {
            break; // Exit the loop when the circular list is traversed
        }
    }
}

// Function to run the elimination game based on the Josephus Problem
Node* runGame(Node* start, int k) {
    Node* curr = start;
    Node* prev = start;

    // Continue the elimination process until only one person is left
    while (curr->next != curr) { // Exit condition: last person standing
        for (int i = 0; i < k; ++i) {
            prev = curr;
            curr = curr->next;
        }

        // Remove the kth node from the circular list
        prev->next = curr->next;
        cout << curr->payload << " voted out!" << endl;
        
        Node* temp = curr;
        curr = curr->next; // Move to the next node
        delete temp; // Free memory for the eliminated node
    }

    return curr; // Last person standing
}

/* Driver program to test above functions */
int main() {
    int n=1, k=1, max; // n = number of names; k = number of skips (minus 1)
    string name;
    vector<string> names;

    // Get inputs for the number of names and the skip count
    cin >> n >> k;

    // Read names until EOF or "." is encountered
    while (cin >> name && name != ".") { names.push_back(name); }

    // Initialize and run the elimination game
    Node* startPerson = loadGame(n, names);
    Node* lastPerson = runGame(startPerson, k);

    // Output the winner or an error message if the game is null
    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
    } else {
        cout << "error: null game" << endl;
    }

    return 0;
}