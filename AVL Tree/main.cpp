#include <iostream>
#include "AVLTree.h"  // Include the header file for the AVLTree class

using namespace std;

// Function to display the menu and get user input
int menu()
{
    int choice = 0;

    // Display the menu options
    cout << endl << "Enter menu choice: ";
    cout << endl;
    cout << "1. Insert" << endl
         << "2. Print" << endl
         << "3. Quit" << endl;

    // Read the user's choice
    cin >> choice;

    // Fix buffer just in case a non-numeric choice is entered
    // Also gets rid of the newline character
    cin.clear();
    cin.ignore(256, '\n');

    return choice;
}

// Main function
int main()
{
    AVLTree tree;  // Create an instance of the AVLTree class

    int choice = menu();  // Get the user's menu choice

    string entry;  // Variable to store user input for insertion

    // Continue processing menu choices until the user chooses to quit (option 3)
    while (choice != 3)
    {
        if (choice == 1)
        {
            cout << "Enter string to insert: ";
            getline(cin, entry);  // Read the string to insert from the user
            cout << endl;

            tree.insert(entry);  // Insert the string into the AVL tree
        }
        else if (choice == 2)
        {
            tree.printBalanceFactors();  // Print the balance factors for all nodes in the AVL tree
        }

        // Fix buffer just in case a non-numeric choice is entered
        choice = menu();  // Get the next menu choice
    }

    return 0;  // Exit the program
}