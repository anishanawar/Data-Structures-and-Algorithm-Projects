#include <cmath> // Standard C library providing mathematical functions
#include <ctime> // Standard C library providing time functions
#include <iostream> // Standard C++ library providing input and output streams

using namespace std; // Using the standard namespace for convenience

const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000; // Constant representing clock ticks per millisecond
const int NUMBERS_SIZE = 50000; // Constant representing the size of arrays

// Function declarations
void Quicksort_midpoint(int[], int, int);
void Quicksort_medianOfThree(int[], int, int);
void InsertionSort(int[], int);
void fillArrays(int[], int[], int[]);
int Partition_midpoint(int[], int, int);
int Partition_medianOfThree(int[], int, int);

int main()
{
    int qMidpoint[NUMBERS_SIZE]; // Array to store numbers for Quicksort using midpoint pivot
    int qMedian[NUMBERS_SIZE]; // Array to store numbers for Quicksort using median-of-three pivot
    int insertion[NUMBERS_SIZE]; // Array to store numbers for Insertion Sort

    fillArrays(qMidpoint, qMedian, insertion); // Fill arrays with random numbers

    clock_t qMidStart = clock(); // Record starting time for Quicksort using midpoint pivot
    Quicksort_midpoint(qMidpoint, 0, NUMBERS_SIZE - 1); // Sort using Quicksort with midpoint pivot
    clock_t qMidEnd = clock(); // Record ending time for Quicksort using midpoint pivot
    int qMidElapsed = (qMidEnd - qMidStart) / CLOCKS_PER_MS; // Calculate elapsed time for Quicksort using midpoint pivot in milliseconds

    cout << "Quicksort (midpoint): " << qMidElapsed << "ms" << endl; // Output elapsed time for Quicksort using midpoint pivot

    clock_t qMedStart = clock(); // Record starting time for Quicksort using median-of-three pivot
    Quicksort_medianOfThree(qMedian, 0, NUMBERS_SIZE - 1); // Sort using Quicksort with median-of-three pivot
    clock_t qMedEnd = clock(); // Record ending time for Quicksort using median-of-three pivot
    int qMedElapsed = (qMedEnd - qMedStart) / CLOCKS_PER_MS; // Calculate elapsed time for Quicksort using median-of-three pivot in milliseconds

    cout << "Quicksort (median of three): " << qMedElapsed << "ms" << endl; // Output elapsed time for Quicksort using median-of-three pivot

    clock_t insertStart = clock(); // Record starting time for Insertion Sort
    InsertionSort(insertion, NUMBERS_SIZE); // Sort using Insertion Sort
    clock_t insertEnd = clock(); // Record ending time for Insertion Sort
    int insertElapsed = (insertEnd - insertStart) / CLOCKS_PER_MS; // Calculate elapsed time for Insertion Sort in milliseconds

    cout << "Insertion Sort: " << insertElapsed << "ms" << endl; // Output elapsed time for Insertion Sort

    return 0;
}

// Quicksort algorithm using the midpoint as pivot
void Quicksort_midpoint(int numbers[], int i, int k)
{
    int j = 0;

    // Base case: If there are 1 or zero elements to sort,
    // partition is already sorted
    if (i >= k)
    {
        return;
    }

    // Partition the data within the array. Value j returned
    // from partitioning is location of last element in low partition.
    j = Partition_midpoint(numbers, i, k);

    // Recursively sort low partition (i to j) and
    // high partition (j + 1 to k)
    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);
}

// Quicksort algorithm using the median of three as pivot
void Quicksort_medianOfThree(int numbers[], int i, int k)
{
    int j = 0;

    // Base case: If there are 1 or zero elements to sort,
    // partition is already sorted
    if (i >= k)
    {
        return;
    }

    // Partition the data within the array. Value j returned
    // from partitioning is location of last element in low partition.
    j = Partition_medianOfThree(numbers, i, k);

    // Recursively sort low partition (i to j) and
    // high partition (j + 1 to k)
    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j + 1, k);
}

// Insertion Sort algorithm
void InsertionSort(int numbers[], int numbersSize)
{
    for (int i = 1; i < numbersSize; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (numbers[j] < numbers[j - 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
            }
        }
    }
}

// Generates a random integer within a given range
int genRandInt(int low, int high)
{
    return low + rand() % (high - low + 1);
}

// Fills arrays with random numbers
void fillArrays(int arr1[], int arr2[], int arr3[])
{
    for (int i = 0; i < NUMBERS_SIZE; ++i)
    {
        arr1[i] = genRandInt(0, NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

// Partition function for Quicksort using midpoint as pivot
int Partition_midpoint(int *numbers, int i, int k)
{
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;

    // Pick middle element as pivot
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    l = i;
    h = k;

    while (!done)
    {
        // Increment l while numbers[l] < pivot
        while (numbers[l] < pivot)
        {
            ++l;
        }

        // Decrement h while pivot < numbers[h]
        while (pivot < numbers[h])
        {
            --h;
        }

        // If there are zero or one elements remaining,
        // all numbers are partitioned. Return h
        if (l >= h)
        {
            done = true;
        }
        else
        {
            // Swap numbers[l] and numbers[h],
            // update l and h
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}

// Partition function for Quicksort using median of three as pivot
int Partition_medianOfThree(int *numbers, int i, int k)
{
    int l = 0;
    int h = 0;
    int midpoint = 0;
   

 int pivot = 0;
    int temp = 0;
    bool done = false;

    // Pick median element as pivot
    midpoint = i + (k - i) / 2;

    if (numbers[midpoint] > numbers[i])
    {
        if (numbers[midpoint] > numbers[k]) // rightmost is median
        {
            pivot = numbers[k];
        }
        else // midpoint is median
        {
            pivot = numbers[midpoint];
        }
    }
    else
    {
        if (numbers[i] > numbers[k]) // rightmost is median
        {
            pivot = numbers[k];
        }
        else // leftmost is median
        {
            pivot = numbers[i];
        }
    }

    l = i;
    h = k;

    while (!done)
    {
        // Increment l while numbers[l] < pivot
        while (numbers[l] < pivot)
        {
            ++l;
        }

        // Decrement h while pivot < numbers[h]
        while (pivot < numbers[h])
        {
            --h;
        }

        // If there are zero or one elements remaining,
        // all numbers are partitioned. Return h
        if (l >= h)
        {
            done = true;
        }
        else
        {
            // Swap numbers[l] and numbers[h],
            // update l and h
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}