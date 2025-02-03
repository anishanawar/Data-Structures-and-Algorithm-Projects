// Including the "Heap.h" header file, which likely contains the declaration of the Heap class.
#include "Heap.h"

// Including the necessary input-output stream header for standard I/O operations.
#include <iostream>

// Using declarations to avoid prefixing standard library elements with "std::".
using std::cin;
using std::cout;
using std::endl;

// Function to display a simple menu and get user input for the choice.
int menu()
{
    // Variable to store the user's choice.
    int choice = 0;

    // Prompting the user to enter their choice.
    cout << endl << "Enter menu choice: ";
    cout << endl;

    // Displaying menu options.
    cout << "1. Enqueue" << endl
         << "2. Print" << endl
         << "3. Dequeue" << endl
         << "4. Quit" << endl;

    // Reading the user's choice.
    cin >> choice;

    // Fixing the buffer just in case a non-numeric choice is entered.
    // Also, clearing any extra characters including the newline character.
    cin.clear();
    cin.ignore(256, '\n');

    // Returning the user's choice.
    return choice;
}

// The main function where the program execution begins.
int main()
{
    // Creating an instance of the Heap class named 'max_heap'.
    Heap max_heap;

    // Getting the user's initial choice from the menu.
    int choice = menu();

    // Looping until the user chooses to quit (option 4).
    while (choice != 4)
    {
        // Handling different menu choices.
        if (choice == 1)
        {
            // Getting input for a print job to enqueue.
            int priority, jobNumber, numPages;
            cout << "Enter print job to enqueue (priority, job Number, number of pages): ";
            cin >> priority >> jobNumber >> numPages;
            cout << endl;

            // Enqueueing the new print job into the max_heap.
            max_heap.enqueue(new PrintJob(priority, jobNumber, numPages));
        }
        else if (choice == 2)
        {
            // Printing the contents of the max_heap.
            max_heap.print();
        }
        else if (choice == 3)
        {
            // Dequeueing a print job from the max_heap.
            max_heap.dequeue();
        }

        // Fixing the buffer just in case a non-numeric choice is entered.
        // Getting the next choice from the user.
        choice = menu();
    }

    // Returning 0 to indicate successful program execution.
    return 0;
}