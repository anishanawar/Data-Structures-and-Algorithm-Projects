#include "Heap.h"   // Include the header file for the Heap class.

#include <iostream> // Include the necessary input-output stream library.

using std::cout;    // Use the cout object from the standard namespace.
using std::endl;    // Use the endl object from the standard namespace.

Heap::Heap()
{
    numItems = 0;    // Initialize the number of items in the heap to zero.
}

void Heap::enqueue(PrintJob* job)
{
    if (numItems != MAX_HEAP_SIZE)  // Check if the heap is not full.
    {
        if (empty())  // Check if the heap is empty.
        {
            arr[numItems] = job;    // Add the job to the heap.
            numItems++;             // Increment the number of items in the heap.
        }
        else
        {
            int currIndex = numItems;   // Initialize the current index to the number of items.
            while (currIndex > 0 && arr[(currIndex - 1) / 2]->getPriority() < job->getPriority())
            {
                arr[currIndex] = arr[(currIndex - 1) / 2];  // Move the parent down.
                currIndex = (currIndex - 1) / 2;            // Move to the parent index.
            }

            arr[currIndex] = job;      // Insert the job at the correct position.
            numItems++;               // Increment the number of items in the heap.
        }
    }
}

void Heap::dequeue()
{
    if (!empty())   // Check if the heap is not empty.
    {
        if (numItems != 1)
        {
            arr[0] = arr[numItems - 1];   // Replace the root with the last element.
        }

        numItems--;   // Decrement the number of items in the heap.
        trickleDown(0);   // Perform trickle-down operation to maintain the heap property.
    }
}

PrintJob* Heap::highest()
{
    return numItems == 0 ? nullptr : arr[0];   // Return the highest priority job if the heap is not empty, otherwise return nullptr.
}

void Heap::print()
{
    if (!empty())  // Check if the heap is not empty.
    {
        cout << "Priority: " << highest()->getPriority()
             << ", Job Number: " << highest()->getJobNumber()
             << ", Number of Pages: " << highest()->getPages();   // Print the priority, job number, and number of pages of the highest priority job.
    }

    cout << endl;   // Print a newline character.
}

void Heap::trickleDown(int index)
{
    if (numItems < index * 2 + 2) // Check if the current index has no children (base case).
    {
        return;   // Return from the function.
    }
    else if (numItems == index * 2 + 2) // Check if the current index has one child (base case).
    {
        if (arr[index]->getPriority() < arr[numItems - 1]->getPriority())
        {
            swap(index, numItems - 1);   // Swap with the only child if the priority is lower.
        }
    }
    else // The current index has two children (do recursion).
    {
        PrintJob* leftChild = arr[index * 2 + 1];   // Get the left child.
        PrintJob* rightChild = arr[index * 2 + 2];  // Get the right child.

        if (leftChild->getPriority() > rightChild->getPriority())
        {
            // Left child is greater, compare it to the current index.
            if (arr[index]->getPriority() < arr[index * 2 + 1]->getPriority())
            {
                swap(index, index * 2 + 1);   // Swap with the left child if the priority is lower.
            }

            trickleDown(index * 2 + 1);   // Recursively call trickleDown on the left child.
        }
        else
        {
            // Right child is greater, compare it to the current index.
            if (arr[index]->getPriority() < arr[index * 2 + 2]->getPriority())
            {
                swap(index, index * 2 + 2);   // Swap with the right child if the priority is lower.
            }

            trickleDown(index * 2 + 2);   // Recursively call trickleDown on the right child.
        }
    }
}

void Heap::swap(int firstIndex, int secondIndex)
{
    PrintJob* temp = arr[firstIndex];    // Temporarily store the job at the first index.
    arr[firstIndex] = arr[secondIndex];  // Swap the job at the first index with the job at the second index.
    arr[secondIndex] = temp;             // Assign the job at the second index to the temp value.
}