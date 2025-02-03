// Including the Jug header file for accessing its functionality.
#include "Jug.h"

// Including the standard input-output stream header file.
#include <iostream>

// The main function where the program execution begins.
int main()
{
    // Declaring a string variable to store the solution.
    std::string solution;

    // Creating an instance of the Jug class with specific parameters.
    Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6);

    // Solving the jug problem and checking if it's solved successfully.
    if (head.solve(solution) != 1)
    {
        // Displaying an error message if solving the jug problem fails.
        std::cout << "Error 3" << std::endl;
    }

    // Displaying the solution for the jug problem.
    std::cout << solution << std::endl << std::endl;

    // Declaring another string variable to store the solution.
    std::string solution2;

    // Creating another instance of the Jug class with different parameters.
    Jug head2(3, 5, 4, 1, 1, 1, 1, 1, 2);
    
    // Solving the second jug problem and checking if it's solved successfully.
    if (head2.solve(solution2) != 1)
    {
        // Displaying an error message if solving the second jug problem fails.
        std::cout << "Error 3" << std::endl;
    }

    // Displaying the solution for the second jug problem.
    std::cout << solution2 << std::endl;

    // Indicating successful termination of the program.
    return 0;
}