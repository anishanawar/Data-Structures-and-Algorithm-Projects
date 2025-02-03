#include "Tree.h"  // Include the header file for the Tree class
#include <iostream>

using namespace std;

// Function to print the orders of the tree: preorder, inorder, and postorder
void printOrders(Tree *tree)
{
    cout << "Preorder = ";
    tree->preOrder();  // Call the preOrder method of the Tree class
    cout << "Inorder = ";
    tree->inOrder();   // Call the inOrder method of the Tree class
    cout << "Postorder = ";
    tree->postOrder();  // Call the postOrder method of the Tree class
}

// Function to display the menu and get the user's choice
int menu()
{
    int choice = 0;
    cout << endl
         << "Enter menu choice: ";
    cout << endl;
    cout
        << "1. Insert" << endl
        << "2. Remove" << endl
        << "3. Print" << endl
        << "4. Search" << endl
        << "5. Quit" << endl;
    cin >> choice;

    // Fix buffer just in case a non-numeric choice is entered
    // Also gets rid of the newline character
    cin.clear();
    cin.ignore(256, '\n');
    return choice;
}

// The main function where the program execution starts
int main()
{
    Tree tree;  // Create an instance of the Tree class

    int choice = menu();  // Get the initial menu choice from the user

    string entry;  // Variable to store user input

    // Main loop for menu-based interactions
    while (choice != 5)
    {
        if (choice == 1)
        {
            cout << "Enter movie title to insert: ";
            getline(cin, entry);  // Get user input for movie title
            cout << endl;

            tree.insert(entry);  // Call the insert method of the Tree class
        }
        else if (choice == 2)
        {
            cout << "Enter movie title to remove: ";
            getline(cin, entry);  // Get user input for movie title to remove
            cout << endl;

            tree.remove(entry);  // Call the remove method of the Tree class
        }
        else if (choice == 3)
        {
            printOrders(&tree);  // Call the printOrders function to display tree orders
        }
        else if (choice == 4)
        {
            cout << "Enter movie title to search for: ";
            getline(cin, entry);  // Get user input for movie title to search
            cout << endl;

            // Check if the movie title is found in the tree
            if (tree.search(entry))
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
        }

        // Fix buffer just in case a non-numeric choice is entered
        choice = menu();  // Get the next menu choice from the user
    }

    return 0;  // Return 0 to indicate successful program execution
}