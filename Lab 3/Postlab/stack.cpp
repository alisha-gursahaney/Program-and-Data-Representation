#include <iostream>
#include "stack.h"
// #include "stackNode.h"

// using namespace std;

// Alisha Meena Gursahaney amg9zd
// post lab 3

// Constructor
stack::stack() {
	// create new list
	head=new stackNode();
    tail=new stackNode();
    head->next=tail;
    tail->previous=head;
    count=0;
}

// destructor
// stack::~stack() {
	// makeEmpty();
	// delete each stack node
	// delete head;
	// head = NULL;
	// delete tail;
	// tail = NULL;
// }

void stack::push(int e) {
// list insertbefore head
// add element to top of the list
	stackNode* temp = new stackNode(); 		// temp pointing to node
	count++; 								// add to count after adding element to list
	temp -> value = e; 						// assigning value of node
	temp -> previous = head; 				// new nodes next and previous
	temp -> next = head -> next; 			// want the next to become the head's original next
	head -> next -> previous = temp; 		//each line rearranging different pointer
	head -> next = temp; 					// points to new list node, after inserted at top
}

void stack::pop() {
	// list remove method with head -> next iterator
	// remove top of the list (first element)
	// int remove = stack.top();
	// remove -> previous -> next = remove -> next;
	// remove -> next -> previous = remove -> previous;
	stackNode* temp = new stackNode(); 
	temp = head -> next;
	temp -> previous -> next = temp -> next;
	temp -> next -> previous = temp -> previous; // or equal to head
	delete temp;
	count --;
}

int stack::top() {
	stackNode* top = new stackNode();
	top = head -> next;
	return top -> value;
}

bool stack::empty() {
// list isEmpty method
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

