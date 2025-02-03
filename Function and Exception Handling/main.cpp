#include <ctime>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::out_of_range;
using std::string;
using std::vector;

// Prototype for the function to find the minimum index starting from a given index
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);

// Prototype for the function to sort the elements using the selection sort algorithm
template<typename T>
void selection_sort(vector<T> &vals);

// Prototype for the function to print the elements of a vector
template<typename T>
void print_vector(vector<T> &vals);

// Prototype for the function to get an element at a given index with bounds checking
template<typename T>
T getElement(vector<T> vals, int index);

// Function to create and return a vector of random characters
vector<char> createVector()
{
    // Generate a random size for the vector (0-25)
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    // Fill in the vector with consecutive characters starting from 'a'
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main()
{
    // Create vectors on the heap to store integers, characters, and strings
    vector<int>* intVector = new vector<int>();
    vector<char>* charVector = new vector<char>();
    vector<string>* stringVector = new vector<string>();

    // Populate the integer vector with some values
    intVector->push_back(9);
    intVector->push_back(333);
    intVector->push_back(7);
    intVector->push_back(10);
    intVector->push_back(42);

    // Sort and print the integer vector
    selection_sort(*intVector);
    print_vector(*intVector);

    // Populate the character vector with some values
    charVector->push_back('a');
    charVector->push_back('w');
    charVector->push_back('1');
    charVector->push_back('*');
    charVector->push_back('A');

    // Sort and print the character vector
    selection_sort(*charVector);
    print_vector(*charVector);

    // Populate the string vector with some values
    stringVector->push_back("bananas");
    stringVector->push_back("apple");
    stringVector->push_back("watermelon");
    stringVector->push_back("kiwi");
    stringVector->push_back("Apple");

    // Sort and print the string vector
    selection_sort(*stringVector);
    print_vector(*stringVector);

    // Exception handling for out_of_range errors 
    try
    {
        // Seed the random number generator
        srand(time(0));

        // Generate and print elements of a randomly sized character vector
        vector<char> vals = createVector();
        char curChar;
        int index;
        int numOfRuns = 10;

        // Loop to allow user input and display of elements
        while(--numOfRuns >= 0){
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals, index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
    }
    catch (out_of_range& excpt)
    {
        // If an exception is caught, print the error message
        cout << excpt.what() << endl;
    }

    // End of program
    return 0;
}

// Template function to find the index of the smallest element starting from 'index'
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned minIndex = index;

    // Loop through elements to find the one that is smallest
    for (unsigned i = index + 1; i < vals.size(); ++i)
    {
        if (vals.at(minIndex) > vals.at(i))
        {
            minIndex = i;
        }
    }

    return minIndex;
}

// Template function for sorting a vector using the selection sort algorithm
template<typename T>
void selection_sort(vector<T> &vals)
{
    // Iterate and select the smallest element to put in front
    for (unsigned i = 0; i + 1 < vals.size(); ++i)
    {
        unsigned minIndex = min_index(vals, i);
        T temp = vals.at(i);
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = temp;
    }
}

// Template function to print all elements of a vector
template<typename T>
void print_vector(vector<T> &vals)
{
    for (unsigned i = 0; i < vals.size(); ++i)
    {
        cout << vals.at(i) << " ";
    }
    cout << endl;
}

// Template function to get the element at a given index with bounds checking
template<typename T>
T getElement(vector<T> vals, int index)
{
    // Convert to unsigned to compare with size() without compiler warning
    unsigned comp = index;
    if (index < 0 || comp >= vals.size())
    {
        // If index is out of bounds, throw an out_of_range exception
        throw out_of_range("out of range exception occurred");
    }

    return vals.at(index);
}