#include "arithmeticExpression.h" // Include the header file for the arithmetic expression class

using std::cout; // Using cout from the standard library
using std::endl; // Using endl from the standard library

int main() // Main function
{
    string expr1 = "a+b*c"; // Define the first arithmetic expression
    arithmeticExpression ex1(expr1); // Create an arithmetic expression object with expr1
    ex1.buildTree(); // Build the expression tree for expr1
    cout << "expression 1: " << expr1 << endl; // Output expression 1
    cout << "infix: "; // Output "infix: "
    ex1.infix(); // Output infix expression for expr1
    cout << endl; // Output new line
    cout << "prefix: "; // Output "prefix: "
    ex1.prefix(); // Output prefix expression for expr1
    cout << endl; // Output new line
    cout << "postfix: "; // Output "postfix: "
    ex1.postfix(); // Output postfix expression for expr1
    cout << endl; // Output new line
    //ex1.visualizeTree("expr1.dot"); // Uncomment to visualize the expression tree for expr1
    cout << endl; // Output new line

    string expr2 = "(a+b)*(c-d)"; // Define the second arithmetic expression
    arithmeticExpression ex2(expr2); // Create an arithmetic expression object with expr2
    ex2.buildTree(); // Build the expression tree for expr2
    cout << "expression 2: " << expr2 << endl; // Output expression 2
    cout << "infix: "; // Output "infix: "
    ex2.infix(); // Output infix expression for expr2
    cout << endl; // Output new line
    cout << "prefix: "; // Output "prefix: "
    ex2.prefix(); // Output prefix expression for expr2
    cout << endl; // Output new line
    cout << "postfix: "; // Output "postfix: "
    ex2.postfix(); // Output postfix expression for expr2
    cout << endl; // Output new line
    //ex2.visualizeTree("expr2.dot"); // Uncomment to visualize the expression tree for expr2
    cout << endl; // Output new line

    string expr3 = "a + b * c - ( d * e + f ) * g"; // Define the third arithmetic expression
    arithmeticExpression ex3(expr3); // Create an arithmetic expression object with expr3
    ex3.buildTree(); // Build the expression tree for expr3
    cout << "expression 3: " << expr3 << endl; // Output expression 3
    cout << "infix: "; // Output "infix: "
    ex3.infix(); // Output infix expression for expr3
    cout << endl; // Output new line
    cout << "prefix: "; // Output "prefix: "
    ex3.prefix(); // Output prefix expression for expr3
    cout << endl; // Output new line
    cout << "postfix: "; // Output "postfix: "
    ex3.postfix(); // Output postfix expression for expr3
    cout << endl; // Output new line
    //ex3.visualizeTree("expr3.dot"); // Uncomment to visualize the expression tree for expr3
    cout << endl; // Output new line

    return 0; // Return 0 to indicate successful completion of the program
}