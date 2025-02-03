#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree
{
private:
    Node *root;

public:
    Tree(); 
    ~Tree(); 
    void insert(const string &); 
    void preOrder() const; 
    void inOrder() const; 
    void postOrder() const; 
    void remove(const string &);
    bool search(const string &) const;

private:
    // Add additional functions/variables here
    void preOrder(Node *) const;
    void inOrder(Node *) const;
    void postOrder(Node *)const;
  
    void insertNode(Node *, const string &); //insert helper function
    void split(Node *,const string &); //splits the tree according to 2-3 rules
    Node *searchNode(Node *, const string &) const; // finds a specific node
    bool isSearchNode(Node *, const string &) const; // helper search function
    void destructorNode(Node *); //destructor helper
};

#endif