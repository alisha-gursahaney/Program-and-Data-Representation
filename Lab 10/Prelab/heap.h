// Alisha Meena Gursahaney
// amg9zd
// prelab 10


#ifndef HEAP_H
#define HEAP_H


#include <iostream>
using namespace std;
#include "heapNode.h"
#include <unordered_map>
#include <vector>
#include <fstream>

class heap{
public:
	// default constructor
	heap();
	// copy constructor
	heap(vector<heapNode*> vec);
	// destructor
	~heap();

	void insert(heapNode* node);

	heapNode* deleteMin();

	heapNode* findMin();

	unsigned int size();

	void makeEmpty();

	bool isEmpty();

	void print();

	unordered_map<string, string> encode(heapNode* root, string s);

	// void outputbits(heapNode* node, string path);

	// unordered_map<string,string> getoutputbits();

private:

	vector<heapNode*> myheap;

	unordered_map<string, string> map;

	// unordered_map <string, string> bitmap;

	unsigned int heap_size;

	void percolateUp(int hole);

	void percolateDown(int hole);
	
};

#endif