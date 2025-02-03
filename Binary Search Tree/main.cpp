#include <iostream>
#include "BSTree.h"

using namespace std;

// Function definition for printing various orders (preorder, inorder, postorder) of a binary search tree.
void printOrders(BSTree *tree) {
  // Output the preorder traversal of the tree.
  cout << "Preorder = ";
  tree->preOrder( );
  
  // Output the inorder traversal of the tree.
  cout << "Inorder = ";
  tree->inOrder( );
  
  // Output the postorder traversal of the tree.
  cout << "Postorder = ";
  tree->postOrder( );
}

// Function definition for displaying a menu and obtaining user choice.
int menu() {
  // Declare and initialize a variable to store the user's choice.
  int choice = 0;
  
  // Output a prompt for the user to enter their menu choice.
  cout << endl << "Enter menu choice: ";
  cout << endl;
  
  // Output the menu options.
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;

  // Read the user's choice from input.
  cin >> choice;
  
  // Fix the input buffer just in case a non-numeric choice is entered, and clear any extra characters.
  cin.clear();
  cin.ignore(256, '\n');
  
  // Return the user's choice.
  return choice;
}

// The main function where the program execution begins.
int main( ) {
  // Create an instance of the BSTree class.
  BSTree tree;

  // Obtain the user's initial choice from the menu.
  int choice = menu();

  // Declare a string variable for user input.
  string entry;
  
  // Loop to handle user interactions until the user chooses to quit (option 8).
  while (choice != 8) {
    
    // Perform actions based on the user's choice.
    if (choice == 1) {
      // Prompt the user to enter a string to insert into the tree.
      cout << "Enter string to insert: ";
      getline(cin, entry);
      cout << endl;
      
      // Insert the entered string into the binary search tree.
      tree.insert(entry);
      
    } else if (choice == 2) {
      // Prompt the user to enter a string to remove from the tree.
      cout << "Enter string to remove: ";
      getline(cin, entry);
      cout << endl;
      
      // Remove the entered string from the binary search tree.
      tree.remove(entry);
      
    } else if (choice == 3) {
      // Print various orders (preorder, inorder, postorder) of the binary search tree.
      printOrders(&tree);
      
    } else if (choice == 4) {
      // Prompt the user to enter a string to search for in the tree.
      cout << "Enter string to search for: ";
      getline(cin, entry);
      cout << endl;
      
      // Check if the entered string is found in the binary search tree and display the result.
      if (tree.search(entry)) {
        cout << "Found" << endl;
      } else {
        cout << "Not Found" << endl;
      }

    } else if (choice == 5) {
      // Display the smallest value in the binary search tree.
      cout << "Smallest: " << tree.smallest() << endl;
      
    } else if (choice == 6) {
      // Display the largest value in the binary search tree.
      cout << "Largest: " << tree.largest() << endl;
      
    } else if (choice == 7) {
      // Prompt the user to enter a string and display the height of the subtree rooted at that string.
      cout << "Enter string: ";
      getline(cin, entry);
      cout << endl;
      cout << "Height of subtree rooted at " << entry << ": " 
        << tree.height(entry) << endl;
        
    }
    // Fix the input buffer just in case a non-numeric choice is entered, and clear any extra characters.
    choice = menu();
  }
  
  // Return 0 to indicate successful program execution.
  return 0;
}