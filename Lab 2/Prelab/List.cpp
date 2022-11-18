#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
using namespace std;

// Constructors and destructors - no return type
List::List() {
	head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List::~List() {

}

void List::insertAtTail(int x) {
	ListNode* temp = new ListNode(); // temp pointing to node
	count++;
	temp -> value = x; // assigning value of node
	temp -> next = tail; // new nodes next and previous
	temp -> previous = tail -> previous; // want the previous to become the tail's original previous
	tail -> previous -> next = temp; //each line rearranging different pointer
	tail -> previous = temp; // points to new list node, after inserted at bottom
}

bool List::isEmpty() const {
	return true;
}

void List::makeEmpty() {

}

ListItr List::first() {
	ListItr firstelement;
	firstelement.current = head->next;
	return firstelement;
}

ListItr List::last() {
	ListItr last;
	return last;
}
	
void List::insertAfter(int x, ListItr position) {

}

void List::insertBefore(int x, ListItr position) {

}

ListItr List::find(int x) {
	ListItr find;
	return find;
}

void List::remove(int x) {

}

int List::size() const {
	return count;
}

void printList(List& source, bool forward) {
	ListItr tempList = source.first();
	if (forward == true) {
		while (tempList.isPastEnd() == false) {
			cout << tempList.retrieve() << endl;
			tempList.moveForward();
		}
	
	}
	else {
		cout << tempList.retrieve() << endl;
		tempList.moveBackward();
	}
}