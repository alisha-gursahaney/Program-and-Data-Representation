// Alisha Meena Gursahaney
// amg9zd
// prelab 10

#include <iostream>
using namespace std;
#include "heap.h"
#include "heapNode.h"
#include <vector>
#include <fstream>
#include <unordered_map>


//constructor
heap::heap() {
	heap_size = 0;
	heapNode* node = new heapNode();
	myheap.push_back(node);
}
	
// copy constructor
heap::heap(vector<heapNode*> vec) : heap_size(vec.size()) {
	myheap = vec;
	myheap.push_back(myheap[0]);
	heapNode* node = new heapNode();
	myheap[0] = node;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// destructor
heap::~heap() {
	makeEmpty();
}

void heap::insert(heapNode* x) {
	// may need to be altered
	myheap.push_back(x);
	percolateUp(++heap_size);
}

heapNode* heap::deleteMin() {

	// may need to be altered
	if (heap_size == 0) {
		throw "deleteMin() called on empty heap";
	}

	heapNode* ret = myheap[1];

	myheap[1] = myheap[heap_size--];

	myheap.pop_back();

	if (!isEmpty()) {
		percolateDown(1);
	}
	return ret;
}

heapNode* heap::findMin() {
	if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return myheap[1];
}

unsigned int heap::size() {
	return heap_size;
}

void heap::makeEmpty() {
	heap_size = 0;
    myheap.resize(1);
}

bool heap::isEmpty() {
	return heap_size == 0;
}

void heap::print() {
	cout << "(" << myheap[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << myheap[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}


void heap::percolateUp(int hole) {
	// get the value just inserted
    heapNode* x = myheap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < myheap[hole/2]); hole /= 2) {
        myheap[hole] = myheap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    myheap[hole] = x;
}

void heap::percolateDown(int hole) {
	// get the value to percolate down
    heapNode* x = myheap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (myheap[child+1] < myheap[child])) {
            child++;
        }
        // if the child is greater than the node...
        if (x > myheap[child]) {
            myheap[hole] = myheap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    myheap[hole] = x;
}

unordered_map<string, string> heap::encode(heapNode* root, string s) {
    	if (root == nullptr) {
    		return map;
    	}
    	string a = "";
    	if (!root->left && !root->right && root->character && root->character != ' ') {
    		a += root->character;
    		map[a] = s;
    		// cout << root->character << " " << s << endl;
    	}


    	
    	// if character is  ' ' change it to say 'space'
    	// if (root->character == ' ') {
    	// 	return map;
    	// 	// cout << "space " << s << endl;
    	// 	//root->character = "space ";
    	// 	// map[root->character] = s;
    	// }

    	encode(root->left, s + "0");
    	encode(root->right, s + "1");

    	return map;
    }

// void heap::outputbits(heapNode* node, string s) {
//   if (node->left != NULL && node->right != NULL) {
//     outputbits(node->right,s+"1");
//     outputbits(node->left,s+"0");
//   }
//   if (node->character == ' ') {
//     bitmap.insert(make_pair("space",s));
//     // cout << "space" << " " << s << endl;
//   }
//   else if (node->character != '=') {
//     char c1 = node->character;
//     string s2 = string(1, c1); 
//     bitmap.insert(make_pair(s2,s));
//     // cout << s2 << " " << s << endl;
//   }
// }

// unordered_map<string,string> heap::getoutputbits() {
//   return bitmap;
// }

// string heap::output(heapNode* root, string s) {
//     	string outputbit = "";
//     	if (root == nullptr) {
//     		return map;
//     	}
//     	string a = "";
//     	if (!root->left && !root->right && root->character && root->character != ' ') {
//     		a += root->character;
//     		// x[a] = s;
//     		outputbit += s;
//     		// cout << root->character << " " << s << endl;
//     	}

//     	output(root->left, s + "0");
//     	output(root->right, s + "1");

//     	return outputbit;
//     }
	
