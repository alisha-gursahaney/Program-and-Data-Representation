/*
 * Filename: stackNode.h
 * Description: stackNode class definition
 */

// Alisha Meena Gursahaney amg9zd
// post lab 3

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
// using namespace std;

class stackNode {

public:
    stackNode();         // Constructor

private:
    int value;          // The value of the node!
    stackNode* next;     // The next stackNode in the List
    stackNode* previous; // The previous stackNode in the list

    // List needs access to value, next, and previous
    friend class stack;

};

#endif
