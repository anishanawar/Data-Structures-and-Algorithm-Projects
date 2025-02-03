#include "Heap.h"        // Include the necessary header files for the Heap class.
#include "PrintJob.h"     // Include the necessary header file for the PrintJob class.

PrintJob::PrintJob(int setP, int setJ, int numP):priority(setP), jobNumber(setJ), numPages(numP) {}
// Constructor for the PrintJob class.
// Initializes the priority, jobNumber, and numPages member variables with the provided values.

int PrintJob::getPriority()
{
    return priority;    // Return the priority of the PrintJob object.
}

int PrintJob::getJobNumber()
{
    return jobNumber;   // Return the job number of the PrintJob object.
}

int PrintJob::getPages ()
{
    return numPages;    // Return the number of pages of the PrintJob object.
}