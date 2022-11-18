#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

ListNode::ListNode() {
	next = NULL;
	previous = NULL;
	value = 0;
}