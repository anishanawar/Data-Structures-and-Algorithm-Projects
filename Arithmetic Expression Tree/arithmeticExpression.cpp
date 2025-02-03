#include "arithmeticExpression.h"  // Include the header file containing the arithmeticExpression class definition

#include <fstream>
#include <sstream>
#include <stack>

using std::cout;
using std::endl;
using std::ostringstream;
using std::stack;

// Function to determine the priority of an operator
int arithmeticExpression::priority(char op)
{
    int priority = 0;

    // Set priority based on the type of operator
    if (op == '(')
    {
        priority = 3;
    }
    else if (op == '*' || op == '/')
    {
        priority = 2;
    }
    else if (op == '+' || op == '-')
    {
        priority = 1;
    }

    return priority;
}

// Convert infix expression to postfix expression
string arithmeticExpression::infix_to_postfix()
{
    stack<char> s;  // Stack to store operators during conversion
    ostringstream oss;
    char c;

    // Loop through each character in the infix expression
    for (unsigned i = 0; i < infixExpression.size(); ++i)
    {
        c = infixExpression.at(i);

        if (c == ' ')
        {
            continue;  // Skip spaces
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') // c is an operator
        {
            if (c == '(')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                // Pop and output operators until the matching '(' is encountered
                while (s.top() != '(')
                {
                    oss << s.top();
                    s.pop();
                }
                s.pop();  // Remove the '(' from the stack
            }
            else
            {
                // Pop and output operators with higher or equal priority
                while (!s.empty() && priority(c) <= priority(s.top()))
                {
                    if (s.top() == '(')
                    {
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);  // Push the current operator onto the stack
            }
        }
        else // c is an operand
        {
            oss << c;
        }
    }

    // Pop and output any remaining operators on the stack
    while (!s.empty())
    {
        oss << s.top();
        s.pop();
    }

    return oss.str();
}

// Constructor for arithmeticExpression class
arithmeticExpression::arithmeticExpression(const string &expr) : infixExpression(expr), root(nullptr) { }

// Build the expression tree
void arithmeticExpression::buildTree()
{
    string postFix = infix_to_postfix();  // Convert infix to postfix expression
    char key = 'a';  // Initialize key for creating unique identifiers for each node

    root = buildNode(postFix, key);  // Build the expression tree from the postfix expression
}

// Recursive function to build a node of the expression tree
TreeNode *arithmeticExpression::buildNode(string &eq, char &key)
{
    if (!eq.empty())
    {
        TreeNode* node = new TreeNode(eq.at(eq.size() - 1), static_cast<char>(key));  // Create a new node with data and identifier
        key++;  // Increment key to generate a unique identifier for the next node
        eq.pop_back();  // Remove the processed character from the postfix expression

        if (priority(node->data) > 0)
        {
            // Recursively build the right and left subtrees for operators
            node->right = buildNode(eq, key);
            node->left = buildNode(eq, key);
        }

        return node;  // Return the created node
    }

    return nullptr;  // Return nullptr when the postfix expression is empty
}

// Print the infix expression corresponding to the expression tree
void arithmeticExpression::infix()
{
    infix(root);
}

// Print the prefix expression corresponding to the expression tree
void arithmeticExpression::prefix()
{
    prefix(root);
}

// Print the postfix expression corresponding to the expression tree
void arithmeticExpression::postfix()
{
    postfix(root);
}

// Recursive functions to print expressions corresponding to the expression tree
void arithmeticExpression::infix(TreeNode *node)
{
    if (node != nullptr)
    {
        if (node->left != nullptr)
        {
            cout << '(';
        }

        infix(node->left);
        cout << node->data;
        infix(node->right);

        if (node->left != nullptr)
        {
            cout << ')';
        }
    }
}

void arithmeticExpression::prefix(TreeNode *node)
{
    if (node != nullptr)
    {
        cout << node->data;
        prefix(node->left);
        prefix(node->right);
    }
}

void arithmeticExpression::postfix(TreeNode *node)
{
    if (node != nullptr)
    {
        postfix(node->left);
        postfix(node->right);
        cout << node->data;
    }
}