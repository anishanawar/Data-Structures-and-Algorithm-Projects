#include <iostream>
using namespace std;
#include "IntList.h"

/*CONSTRUCTOR - Initializes an empty list with dummy head and dummy tail*/
// dummyHead precedes the first node in the list and dummyTail follows the last node in the list.
IntList::IntList(){
    dummyHead = dummyTail = new IntNode(0);
}

/*DESTRUCTOR - Deallocates all remaining dynamically allocated memory.*/
// checks if the list is empty, if it is not, it keeps calling pop_front to remove the first node until the list is empty.
IntList::~IntList(){
    //loops runs until the list is empty.
    while (!empty()){
        //removes the first node in the list.
        pop_front(); 
    }
}

/*COPY ASSIGNMENT OPERATOR*/
IntList &IntList::operator=(const IntList &rhs){
    //conditional runs if the list is empty.
    if (this != &rhs && rhs.empty()){
        //sets dummyHead and dummyTail to nullptr
        dummyHead = dummyTail = nullptr; 
        return *this;
    }
    //intializes currNode to a rhs' dummyHead
    IntNode *currentNode = rhs.dummyHead; 
    //head tail node set.
    //conditional runs due to currNode being declared as a dummyHead.
    if (currentNode){ 
        //this instance points to dummyHead and makes it a new IntNode with the current data values
        this->dummyHead = new IntNode(currentNode->data); 
        //sets this dummyTail as the dummyHead as there is one node.
        this->dummyTail = dummyHead; 
        //sets currNode to its next node.
        currentNode = currentNode->next; 
    }

   //loop iterates to set tail to last node until no more nodes.
    while (currentNode){
        //intializes new IntNode with the currNode's rhs data.
        IntNode *t = new IntNode(currentNode->data); 
        //sets dummyTail's next to the new IntNode
        dummyTail->next = t;
        //sets the dummyTail to the new IntNode                         
        dummyTail = t; 
        //increments currentNode to next for the loop                              
        currentNode = currentNode->next;            
    }
    return *this;
}

/*COPY CONSTRUCTOR*/
//intializes dummyHead and dummyTail to empty list.
IntList::IntList(const IntList &cpy) : dummyHead(0), dummyTail(0){
    //intializes currNode to a dummyHead copy
    IntNode *currentNode = cpy.dummyHead; 
    //head tail node set.
    //conditional runs due to the copy dummyHead being initialized.
    if (currentNode){
        //dummyHead is initialized to a new IntNode with the same data as the copy dummyHead.
        dummyHead = new IntNode(currentNode->data); 
        //sets the dummyTail as the dummyHead as there is one node.
        dummyTail = dummyHead; 
        //sets currNode to its next node.
        currentNode = currentNode->next; 
    }

    //loop iterates to set tail to last node until no more nodes.
    while (currentNode){
        //intializes new IntNode with the currNode's copied data.
        IntNode *t = new IntNode(currentNode->data); 
        //sets dummyTail's next to the new IntNode
        dummyTail->next = t; 
        //sets the dummyTail to the new IntNode
        dummyTail = t; 
        //increments currentNode to next for the loop
        currentNode = currentNode->next; 
    }
}

/*PUSH FRONT - Inserts a data value (within a new node) at the front end of the list.*/
void IntList::push_front(int value){
    //initializes currNode to be the new node to push front's value.
    IntNode *currNode = new IntNode(value); 
    //conditional runs if there is no node in the list.
    if (!dummyHead->next){
        //the value is added and set as both the first (dummyHead->next) and last(dummyTail->prev) node.
        dummyHead->next = dummyTail->prev = currNode; 
        //thus, currNode's next pointer is the new dummyTail
        currNode->next = dummyTail;                   
        //and currNode's prev pointer is the new dummyHead
        currNode->prev = dummyHead;                  
    }
    else{
        //initializes a variable pointing at the 'head' node.
        IntNode *t = dummyHead->next; 
        //sets currNode's next to the first node.
        currNode->next = t;     
        //sets the first node to currNode.      
        dummyHead->next = currNode;   
        //sets the value preceeding the first node (now our currNode) to the dummyHead;
        currNode->prev = dummyHead;  
        //sets the dummyHead to currNode. 
        t->prev = currNode;           
    }
}

/*POP FRONT - Removes the node at the front end of the list (the node after the dummy head).*/
void IntList::pop_front(){
    //initializes the currNode to be essentially 'head->next'
    IntNode *currNode = dummyHead->next->next; 
    //conditional runs if there exists a node in the list.
    if (dummyHead->next){
        //conditional runs if the currNode is not the only node.
        if (currNode != dummyTail){
            //removes the first node.
            delete dummyHead->next;    
            //sets the first node to currNode, which is the node after the (removed) first node.
            dummyHead->next = currNode;
            //sets the dummyHead as preceding the first node in the list.
            currNode->prev = dummyHead;
        }
        else{
            //otherwise, if currNode is the only node, the 'tail' is deleted
            delete dummyHead->next;   
            //and the first and last node is set to nullptr                   
            dummyHead->next = dummyTail->prev = nullptr; 
        }
    }
}

/*PUSH BACK - Inserts a data value (within a new node) at the back end of the list. */
void IntList::push_back(int value){
    //initializes currNode to be the new node to push back's value.
    IntNode *currNode = new IntNode(value);
    //conditional runs if there is no node in the list.
    if (!dummyHead->next){
        //the value is added and set as both the first (dummyHead->next) and last(dummyTail->prev) node.
        dummyHead->next = dummyTail->prev = currNode; 
        //thus, currNode's next pointer is the new dummyTail
        currNode->next = dummyTail;    
        //and currNode's prev pointer is the new dummyHead              
        currNode->prev = dummyHead;                   
    }
    else{
        //initializes a variable pointing at the 'tail' node.
        IntNode *t = dummyTail->prev; 
        //sets the last node to currNode.
        dummyTail->prev = currNode;   
        //sets the last node (now our currNode)'s next to dummyTail.
        currNode->next = dummyTail;   
        //sets currNode's prev to the last node.
        currNode->prev = t;   
        //sets the dummyTail to currNode.        
        t->next = currNode;          
    }
}

/*POP BACK -  Removes the node at the back end of the list (the node before the dummy tail). */
void IntList::pop_back(){
    //initializes the currNode to be the last node's prev pointer
    IntNode *currNode = dummyTail->prev->prev; 
    //conditional runs if there exists a node in the list
    if (dummyHead->next){
        //conditional runs if the currNode is not the only node.
        if (currNode != dummyHead){
             //removes the first node.
            delete dummyTail->prev;    
            //sets the last node to currNode, which is the node after the (removed) last node.
            dummyTail->prev = currNode; 
            //sets the dummyTail as succeeding the last node in the list.
            currNode->next = dummyTail; 
        }
        else{
            //otherwise, if the currNode is the only node, the 'head' is deleted.
            delete dummyHead->next;         
            //and the first and last node is set to nullptr.            
            dummyHead->next = dummyTail->prev = nullptr;
        }
    }
}

/*EMPTY -  Returns true if the list does not store any data values*/
bool IntList::empty() const{
    return !dummyHead->next; //returns true if there is no first node.
}

/*OSTREAM OPERATOR - A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. */
ostream &operator<<(ostream &out, const IntList &rhs){
    //conditional runs if rhs has a node.
    if (rhs.dummyHead->next){
        //initializes currNode to rhs's first node.
        IntNode *currNode = rhs.dummyHead->next;
        //loops until currNode reaches the end of the list
        while (currNode != rhs.dummyTail){
            //prints out currNode's data
            out << currNode->data;     
            //conditional runs as long as currNode is not the last node          
            if (currNode != rhs.dummyTail->prev){
                //adds a space in between every value, except for the last one.
                out << " "; 
            }
            //iterates through the loop by incrementing the currNode.
            currNode = currNode->next;
        }
    }
    return out;
}
/*PRINT REVERSE - prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space.*/
void IntList::printReverse() const{
    //initializes variable to iterate with the last node.
    IntNode *i = dummyTail->prev; 
    //conditional runs as long as the list isn't empty.
    if (!empty()){
        //loops iterates until i equals the dummyHead
        while (i != dummyHead){
            //prints out i's data.
            cout << i->data; 
            //conditional runs as long as i is not the first node
            if (i->prev != dummyHead){
                //adds a space in between every value, except for the last one printed.
                cout << " "; 
            }
            //iterates through the loop backwards by decrementing i;
            i = i->prev; 
        }
    }
}