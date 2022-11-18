#ifndef STACK_H
#define STACK_H
#include "stackNode.h"

#include <iostream>
// using namespace std;

// Alisha Meena Gursahaney amg9zd
// post lab 3

class stack {
public:
	// default constructor
	stack();

	//destructor
	// ~stack();

	// pushes element to top of the list
	void push(int e);

	// deletes the first elements of the list
	void pop();

	// looks at top of list
	int top();

	// returns true if list is empty
	bool empty();

private:
	stackNode* head;
	stackNode* tail;
	int count;
};


#endif