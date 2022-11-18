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
	makeEmpty();
	delete head;
	head = NULL;
	delete tail;
	tail = NULL;
	// delete pointers ??
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
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

ListItr List::first() {
	ListItr atFirst(head -> next);
	return atFirst;
	/*ListItr first;
	first.current = head -> next;
	return first;
	*/
}

ListItr List::last() {
	ListItr last;
	last.current = tail -> previous;
	return last;
}

// create new ListItr ???
void List::makeEmpty() {
	ListItr i = first();
	ListNode* temp = i.current -> next;
	while (i.isPastEnd() == false) {
		i.current -> previous -> next = i.current -> next;
		i.current -> next -> previous = i.current -> previous;
		delete(i.current);
		//(*this).remove(i.current -> value);
		i.current = temp;
		temp = temp -> next;
		count--;
	}
}
	
void List::insertAfter(int x, ListItr position) {
	ListNode* after = new ListNode(); // after pointing to node
	count++;
	after -> value = x; // assigning value of node
	after -> previous = position.current;
	after -> next = position.current -> next;
	after -> previous -> next = after;
	after -> next -> previous = after;
}

void List::insertBefore(int x, ListItr position) {
	ListNode* before = new ListNode(); // before pointing to node
	count++;
	before -> value = x; // assigning value of node
	before -> next = position.current; // .current = itr node
	before -> previous = position.current -> previous;
	before -> next -> previous = before;
	before -> previous -> next = before;
}

ListItr List::find(int x) {
	ListItr i(head -> next);
	// i.current = head -> next;
	while (i.isPastEnd() == false) {
		if (i.current -> value == x) {
			return i;
		}
		else {
			i.moveForward();
		}
	}
	return i;
}

void List::remove(int x) {
	ListItr remove = find(x);
	if (remove.current == tail) {
		return;
	 }	// value not in list
		remove.current -> previous -> next = remove.current -> next;
		remove.current -> next -> previous = remove.current -> previous;
		delete remove.current;
		remove.current = NULL;
		count--;
	//}

}

int List::size() const {
	return count;
}

void printList(List& source, bool forward) {
	if (forward == true) {
		ListItr tempList = source.first();
		while (tempList.isPastEnd() == false) {
			cout << tempList.retrieve() << endl;
			tempList.moveForward();
		}
	
	}
	else {
		ListItr tempList = source.last();
		while (tempList.isPastBeginning() == false) {
			cout << tempList.retrieve() << endl;
			tempList.moveBackward();
		}
	}
}