#include "Tree.h"
//constructor
Tree::Tree()
{
    root = nullptr;
}
//destructor helper
void Tree::destructorNode(Node *node)
{ // recursively deletes nodes
    if (node)
    {//if there's a node, it recursively deletes all branches
        destructorNode(node->left);
        destructorNode(node->middle);
        destructorNode(node->right);
        
        delete node;
    }

}
//destructor
Tree::~Tree()
{
   destructorNode(root);
}
//inserts string into node in accordance to 2-3 rules
void Tree::insert(const string &str)
{
    if (!root)
    { // if empty, insert str into a new node.
        root = new Node(str);
    }
    else
    {//calls insertNode function to insert string
        insertNode(root, str);
    }
}
//insert helper function
void Tree::insertNode(Node* node, const string &str)
{
    while (node)
    {//runs until we insert the node.
        if (str < node->small)
        { // case if the str is smaller than the nodeent node's small
            if (node->left)
            { // if the left exists, iterate node to left
                node = node->left;
            }
           
        }
        else if ((node->small != "" && node->large == "") || (str > node->small && str < node->large))
        { //
            if (node->middle)
            { // iterates to mid
                node = node->middle;
            }
            
        }
        else
        { // case for if the insert str is greater than the nodeent nodes large str
            if (node->right)
            { //traversing the right
                node = node->right;
            }
        }
        if (node->isFull())
        { // node is full, need to call split.
            // end function after splitting.
            split(node,str);
            break;
        }
        else
        { // just insert if not full
            if (str > node->small)
            { // insert into large slot if str is bigger
                node->large = str;
            }
            else
            {
                // insert the previously smaller string to the large slot
                // give that small slot to str
                node->large = node->small;
                node->small = str;
            }
            break;
        }
    }
}

void Tree::split(Node *node, const string &str)
{
    string mid;
    //find where to put the middle value when splitting the node
    if (str < node->small)
    { // if str is smallest 
    //make mid the nodes's small, and the node small's prev slot the str
        mid = node->small;
        node->small = str;
    }
    else if (str < node->large)
    { // str is the mid
        mid = str;  
    }
    else
    { // if the str is largest
    //made mid the node's large and the node large's prev slot the str
        mid = node->large;
        node->large = str;
    }

    if (node == root)
    {     //case where node is root, split    

        //set left to new node containing small string
        node->left = new Node(node->small); 
        node->left->parent = root;          
        //set middle to new node containing large string
        node->middle = new Node(node->large);
        node->middle->parent = root;      

        // the small is set to mid and the large is cleared
        node->small = mid;
       
    }
    else
    {//else, not the root split case.
    
        node->parent->large = mid;  
        //insert to the parent's right
        node->parent->right = new Node(str); 
                       
    }
    //clear out the large slot for all
    node->large = "";
}

void Tree::preOrder() const
{//calls preOrder helper
    preOrder(root);
    cout << endl;
}
void Tree::inOrder() const
{//calls inOrder helper
    inOrder(root);
    cout << endl;
}
void Tree::postOrder() const
{//calls postOrder helper
    postOrder(root);
    cout << endl;
}
//recursive helper for preOrder
void Tree::preOrder(Node *node) const
{
    if (node)
    {//if the node is full, it prints both the small and large recursively
        if (node->isFull())
        {
            cout << node->small << ", ";
            preOrder(node->left);
            cout << node->large << ", ";
            preOrder(node->middle);
            preOrder(node->right);
        }
        else
        {//otherwise it just prints the small in node recursively
            cout << node->small << ", ";
            preOrder(node->left);
            preOrder(node->middle);
        }
    }
}
//recursive helper for inOrder
void Tree::inOrder(Node *node) const
{
    if (node)
    {//if node is full, it prints both small and large recursively
        if (node->isFull())
        {
            inOrder(node->left);
            cout << node->small << ", ";
            inOrder(node->middle);
            cout << node->large << ", ";
            inOrder(node->right);
        }
        else
        {//otherwise it just prints small recursively
            inOrder(node->left);
            cout << node->small << ", ";
            inOrder(node->middle);
        }
    }
}
//recursive helper for postOrder
void Tree::postOrder(Node *node) const
{

    if (node)
    {//if node is full it prints small and large recursively
        if (node->isFull())
        {
            postOrder(node->left);
            postOrder(node->middle);
            cout << node->small << ", ";
            postOrder(node->right);
            cout << node->large << ", ";
        }
        else
        {//otherwise it just prints out small recursively
            postOrder(node->left);
            postOrder(node->middle);
            cout << node->small << ", ";
        }
    }
}

//removes a string from node
void Tree::remove(const string &str)
{
    //intializes the node we want to remove via search function
    Node *curr = searchNode(root, str);

    if (curr)
    {
        if (curr->isFull()) 
        {//if the node is full, just remove.
            if (curr->large == str)
            {
            // if it's in large spot just remove
                curr->large = ""; 
            }
            else // if its in small spot
            {//set small to large value and clear the large.
                curr->small = curr->large;
                curr->large = ""; 
            }
        }
        else //the node is not full.
        {
            Node *parent = curr->parent;
            if (!parent) // case of no parents (orphans)
            {
                Node *newNode = new Node();

                if (root->left)
                {//if the root has left child, set the small and large 
                //of the newNode's to its respective child
                //and then make root node the newNode
                    newNode->small = root->left->small;   
                    newNode->large = root->middle->small;
                    root = newNode;                  
                }
                else
                {
                    delete root; //remove if there is no child
                    root = nullptr; 
                }
            }
            else // there is a parent, case.
            {
                if (parent->small > str) 
                {//if the parent's string is larger than your string.
                //remove the desired node
                    delete parent->left;
                    parent->left = nullptr; 
                    //give the parent's middle child the large spot
                    parent->large = parent->middle->small;
                    //remove the middle child after
                    delete parent->middle; 
                    parent->middle = nullptr; 
                }
                else // if the parent's string is smaller than your string
                {
                    //remove the desired node
                    delete parent->middle;
                    parent->middle = nullptr; 
                    //gives the parent's small child the large spot
                    parent->large = parent->small;  
                    // move the left child to now empty small slot  
                    parent->small = parent->left->small; 
                    //remove the left child after
                    delete parent->left;
                    parent->left = nullptr;
                }
            }
        }
    }
}

//search function retures true if found.
bool Tree::search(const string &str) const
{//calls the isSearchNode helper
    return isSearchNode(root, str);
}

//helper for search function
bool Tree::isSearchNode(Node *node, const string &str) const
{
    if (node)
    {
        if (node->small == str || (node->isFull() && node->large == str))
        { // returns true if the string matches current node.
            return true;
        }
        else
        { // if the string isn't found, recursively
          // move either left/right down the tree until found.
            if (node->small > str)
            { // recursively runs the node's left child
              // when the str is less than current node
                return searchNode(node->left, str);
            }
            else
            {
                if (node->isFull() && node->large < str)
                {
                    // larger than both strings, so go recursively right
                    return searchNode(node->right, str);
                }
                else
                {
                    // in middle, go to the middle
                    return searchNode(node->middle, str);
                }
            }
        }
    }
    return false; // no node found
}

//returns the node found from search
Node *Tree::searchNode(Node *node, const string &str) const
{
    if (node)
    {
        if (node->small == str || (node->isFull() && node->large == str))
        { // returns node if the string matches current node.
            return node;
        }
        else
        { // if the string isn't found, recursively
          // move either left/right down the tree until found.
            if (node->small > str)
            { // recursively runs the node's left child
                // when the str is less than current node
                return searchNode(node->left, str); // returns node when found
            }
            else
            {
                if (node->isFull() && node->large < str)
                {
                    // larger than both strings, recursive right until found
                    return searchNode(node->right, str);
                }
                else
                {
                    // in middle or one child, go to the middle and return
                    return searchNode(node->middle, str);
                }
            }
        }
    }
    return nullptr; //no node found
}