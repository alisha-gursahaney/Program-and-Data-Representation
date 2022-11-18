// Alisha Meena Gursahaney
// amg9zd
// inlab10

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <unordered_map>
// #include "heapNode.h"
using namespace std;


// how to check the character within the string prefix
// recursing with the string

// instead of building a tree, use a hash table with an unordered map
// void buildTree(heapNode* node, string prefix, string c) {
// 	// if (node == NULL) {
// 	// 	// node = new heapNode();
// 	// 	// node->character = c[0];
// 	// 	return;
// 	// }
// 	if (prefix.length() == 0) {
// 		// heapNode* node = new heapNode();
// 		node->character = c[0];
// 		// cout << c ;
// 		return;
// 	}

// 	// if (node->character == '-') {
// 	// 	return;
// 	// }

// 	// if (node != NULL) {
// 	//else {
// 		//if (!node->right && !node ->left) {
// 		// add 1 when calling on right child
// 		// prefix 0
// 	else if (!node -> right && prefix[0] == '1') {
// 			// heapNode* temp = new heapNode();
// 			// node -> right = temp;
// 			node -> right = new heapNode();
// 			// cout << c;
// 			//temp->character = c[0];
// 			// start at 1, end at length-1
// 			buildTree(node->right, prefix.substr(1, prefix.length()-1), c);
// 			}
// 		// add 0 when calling on left child
// 	else if (!node -> left && prefix[0] == '0') {
// 			// heapNode* temp = new heapNode();
// 			// node -> left = temp;
// 			node -> left = new heapNode();
// 			// cout << c;
// 			//temp->character = c[0];
// 			buildTree(node->left, prefix.substr(1, prefix.length()-1), c);
// 			}
		//}
	// node is a leaf
	// buildTree(node, prefix.substr(1, prefix.length()-1));
// 	node -> character = c[0];
// 	// cout << c;
// }
unordered_map<string, string> prefixmap;

// void prefixDecode(heapNode* node, string prefix) {
// 	if (node == NULL) {
// 		// node = new heapNode();
// 		//node->character = 
// 		return;
// 	}
// 	if (prefix.length() < 1) {
// 		return;
// 	}

// 	// if (node->character == '-') {
// 	// 	return;
// 	// }
// 	// node is a leaf, return its character
// 	if (!node->right && !node->left) {
// 		cout << node->character;
// 	}

// 	// if (node != NULL) {
// 	else {
// 		//if (!node->right && !node ->left) {
// 		// add 1 when calling on right child
// 		// prefix 0
// 		if (!node -> right && prefix[0] == '1') {
// 			// node -> right = new heapNode();
// 			// cout << node->character;
// 			// start at 1, end at length-1
// 			prefixDecode(node->right, prefix.substr(1, prefix.length()-1));
// 			}
// 		// add 0 when calling on left child
// 		if (!node -> left && prefix[0] == '0') {
// 			// node -> left = new heapNode();
// 			// cout << node->character;
// 			prefixDecode(node->left, prefix.substr(1, prefix.length()-1));

// 			}
// 		}
// 	// node is a leaf
// 	cout << node->character;
// 	// cout << c;
// }


// from inlab-skeleton
// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // begin editing
   
    // unordered_map<string,string> tree;

    // heapNode* root;
    // char ascii[256];
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;

        
        // tree.insert(prefix, character);
        // ADD TO HEAP TREE
        // if(node == NULL) {
        // 	node = new heapNode();
        // }
        // // if(node->left == NULL) {

        // // }
        // // if(node->right == NULL) {

        // // }
        // if(!node->left && !node->right) {
        // 	cout << character[0];
        // }

        // create the tree

        // for (int i = 0; i < prefix.length(); i++) {
        // 	if(prefix[i] == '0' && !node->left) {
        // 		node->left = new heapNode();
        // 		// node->left->frequency = 1;
        // 		// node->left->character = '0';
        // 	}
        // 	if(prefix[i] == '1' && !node->right) {
        // 		node->right = new heapNode();
        // 		// node-right->frequency = 1;
        // 		// node->right->character = '1';
        // 	}

        // }
        // buildTree(root, prefix, character);
        // cout << endl;
        prefixmap.insert(make_pair(prefix, character));

        // do something with the prefix code
        // cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // heapNode* node = new heapNode();
    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }

        
        // add it to the stringstream
        sstm << bits;
        
    }

    string allbits = sstm.str();

    // prefixDecode(node, allbits);
    // googled how to iterate through hash map

    
    string decode_phrase = "";
    string letter;
    //while(!allbits.enbreakd()) {
    for (int i = 0; i <= allbits.size(); i++) {
    	
    	unordered_map<string, string>::iterator z = prefixmap.find(letter);
    	
    	if (z != prefixmap.end()) {
    		decode_phrase += prefixmap[letter];
    		
    		// prefixmap.find(letter);
    		// decode_phrase += allbits[]
    		letter = "";
    		//i++;
    	}
    	else {
    		// return;
    	}
    	letter += allbits[i];
    }
    cout << decode_phrase << endl; 
    //<< endl;

    // cout << endl;

    // EDIT TREE
    // heapNode* root = node;
    // // read and print out contents of tree
    // for (int i = 0; i < allbits.length(); i++) {
    //    	if (!root->left && !root->right) {
    //     	cout << root -> character;
    //     	// reset node so that for loop can continue
    //     	root = node;
    //     }
    //     else if (allbits[i] == '0') {
    //     	root = root->left;
    // 	}
    // 	else if (allbits[i] == '1') {
    // 		root = root->right;
    // 	}
    // }

    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();

    return 0;
}
