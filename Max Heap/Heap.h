#include "Heap.h"

#ifndef __HEAP_H__
#define __HEAP_H__

#include "PrintJob.h"

// Maximum size of the heap
const int MAX_HEAP_SIZE = 10;

// Class definition for Heap
class Heap
{
  private:
    // Array of PrintJob pointers representing the heap
    PrintJob* arr[MAX_HEAP_SIZE]; // Notice this is an array of PrintJob pointers
    int numItems;  // Current number of items in the heap
    
  public:
    // Default constructor to initialize an empty heap
    Heap();

    /*
     * Inserts a PrintJob to the heap without
     * violating max-heap properties.
     */
    void enqueue(PrintJob*);

    /*
     * Removes the node with the highest priority from the heap.
     * Follow the algorithm on priority-queue slides.
     */
    void dequeue();

    /* Returns the node with the highest priority. */
    PrintJob* highest();

    /*
     * Prints the PrintJob with the highest priority in the following format:
     * Priority: priority, Job Number: jobNum, Number of Pages: numPages
     * (Add a new line at the end.)
     */
    void print();
    
  private:
    /*
     * This function is called by the dequeue function
     * to move the new root down the heap to the
     * appropriate location.
     */
    void trickleDown(int);

    /*
     * Swap two values in arr given two indices.
     */
    void swap(int, int);

    // Additional private helper function to check if the heap is empty
    bool empty() const
    {
        return numItems == 0;
    }
};

#endif