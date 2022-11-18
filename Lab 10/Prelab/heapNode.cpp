// Alisha Meena Gursahaney
// amg9zd
// prelab 10


#include <iostream>
using namespace std;
#include "heapNode.h"


// default constructor
heapNode::heapNode() {
	frequency = 0;
	character = ' ';
	left = NULL;
	right = NULL;
}

// copy constructor
heapNode::heapNode(char character1, int frequency1) {
	frequency = frequency1;
	character = character1;
	left = NULL;
	right = NULL;
}

// destructor
heapNode::~heapNode() {
	delete left;
	delete right;
}

// use pointers instead
// int heapNode::getFreq() {
// 	return frequency;
// }

// char heapNode::getChar() {
// 	return character;
// }

// heapNode* heapNode::getLeft() {
// 	return left;
// }


// heapNode* heapNode::getRight() {
// 	return right;
// }
