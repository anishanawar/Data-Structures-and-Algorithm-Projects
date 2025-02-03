#ifndef __PRINTJOB_H__  // Header guard to prevent multiple inclusion
#define __PRINTJOB_H__

class PrintJob
{
  private:
    int priority;       // Private member variable to store the priority of the print job
    int jobNumber;      // Private member variable to store the job number
    int numPages;       // Private member variable to store the number of pages in the print job

  public:
    // Constructor to initialize the PrintJob object with given values
    PrintJob(int priority, int jobNumber, int numPages);

    // Getter function to retrieve the priority of the print job
    int getPriority();

    // Getter function to retrieve the job number of the print job
    int getJobNumber();

    // Getter function to retrieve the number of pages in the print job
    int getPages();

};
#endif  // __PRINTJOB_H__