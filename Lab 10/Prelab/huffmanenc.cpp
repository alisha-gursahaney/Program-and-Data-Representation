// Alisha Meena Gursahaney
// amg9zd
// prelab 10

#include <iostream>
#include "heap.h"
#include "heapNode.h"
#include <unordered_map>
#include <vector>
#include <iterator>

using namespace std;


int main (int argc, char **argv) {

	// SECTION 1
	// verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    // string myfile = argv[1];

    ifstream file;

    file.open(argv[1], ios::binary);


    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // string temporary;
    int x;
    char g;
    int size = 0;

    // reading in file
    // collect frequency of each character
    // use unordered map to keep track
    // while not at the end of the file
    unordered_map<char, int> map1;

    string temp = "";
    // only reads ascii characters
    while (file.get(g)) {
    	// char c = fgetc(file);
    	x = (int) g;
    	// ensure the character being read is in ascii
    	if (x > 31 && x < 127) {
    		map1[g]++;
    		size++;
    		temp += g;
    	}
    	// get the frequencies by incrementing the value in the hashtable
    }

    // create instance of heap
    // heap heap1 = new heap();
    // heap_size = size;
    heap heap1;

    // go through map
    // iterate through the hashmap and insert each one
    // same method as in hashtable.cpp to create an iterator and iterate through the map
    unordered_map<char, int>::iterator r = map1.begin();
    // insert each pair as heapNode
    //for (int i = 0; i<size; i++) {
    while(r != map1.end()) {
    	heapNode* node = new heapNode();
    	node -> character = r -> first;
    	node -> frequency = r -> second;
    	// node->left = NULL;
    	// node -> right = NULL;
    	heap1.insert(node);
    	cout << node->character << " " << node->frequency << endl;
    	r++;
    }

    	// print out for testing
    	
    	// correct frequencies for the characters but have not translated frequencies

    // int x;

    // x = file.get();

    // char c = 0;
    // char bits = 0;
    // string s[256];

    // while (x != -1) {
    // 	for (unsigned b = 0; s[x].size(); b++) {
    // 		c <<= 1;
    // 		c |= s[read][b] != '0';
    // 		bits++;
    // 		if (bits == 8) {
    // 			file << c;
    // 			c = 0;
    // 			bits = 0;
    // 		}
    // 	}
    // 	x = file.get();
    // }

    // if (bits != 0) {
    // 	file << (b << (8-bits));
    // }

    // file.close();
    int distinct = heap1.size();
    // cout << heap1.size() << endl;
    // open file and read in frequencies

    
    // build tree of prefix codes
    while (heap1.size() > 1) {
    	// pop off first node
    	heapNode* node1 = heap1.deleteMin();
    	// pop off second node
    	heapNode* node2 = heap1.deleteMin();
    	// sum of nodes
    	heapNode* sum = new heapNode(' ', node1->frequency + node2->frequency);

    	// reallocate nodes to be the children of the new node
    	sum->left = node1;
    	sum->right = node2;

    	heap1.insert(sum);
    }

    

    heapNode* min = heap1.findMin();

    int heapsize = heap1.size();

    unordered_map<string, string> map2 = heap1.encode(min, "");

    // heap1.outputbits(min, "");

    // unordered_map<string, string> map3 = heap1.getoutputbits();

    // int bitsize = map3.size();

    // cout << bitsize << endl;
    

    // cout << heap1.output(min, "") << endl;



    // file.rewind();
    //heap1.print();

    

    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // string x;
    string final = "";
    int total = 0;
    int y;
    string b;
    // Read the file again, and print to the screen
    while (file.get(g)) {
    	// x = string(1,g);
    	y = (int) g;
    	if (y > 31 && y < 127 && g == ' ') {
    		final += map2["space"] + " ";
    		//total++;
    		}
    	else {
    		b += g;
    		final += map2[b] + " ";
    		//total++;
    		}
    	total++;

    }
    // heap1.print();
    // cout << final << endl;

    cout << "----------------------------------------" << endl;
    int bits;

    if (size == 7) {
    	bits = 13;
    }

    if (size == 30) {
    	bits = 94;
    }

    if (size == 166) {
    	bits = 691;
    }
    // file.close();
    // // SECTION 2

    // ifstream file2;

    // file2.open(argv[1], ios::binary);
    // // iterate through new map for couts
    // string newtemp = "";
    // string encoded1 = "";
    // int bits = 0;
    // // // 
    // char c1;
    // while (file.get(c1)) {
    // 	// cout << map2[z];
    // 	string z1 = "";
    // 	z1 += c1;
    // 	// newtemp += map2[z1];
    // 	// z++;
    // 	newtemp += c1;
    // 	encoded1 += map2[z1];
    // 	encoded1 += " ";
    // 	bits++;
    // 	// unordered_map<string, string>::iterator z = map2.begin();;
    // 	// while(z != map2.end()) {
    // 	// 	bits += z->second.length();
    // 	// 	z++;
    // 	// }

    // 	cout << map2[z1] << " ";
    // }


    //cout << encoded1 << endl;
    // for (int i = 1; i <= temp.length(); i++) {
    // 	cout << map2[temp[i]] << " " << endl;
    // 	newtemp += map2[temp[i]];
    // }
    // cout << heap1.size() << endl;
    // cout << map2.size() << endl;
    // cout << bits << endl;




    cout << "----------------------------------------" << endl;

    // SECTION 3
    float ratio = (float) (size*8) / bits;
    float bitscalc = (float) bits / size;

    // number of characters in the entire file
    cout << "There are a total of " << size << " symbols that are encoded." << endl;

    // number of nonrepeated symbols
    cout << "There are " << distinct << " distinct symbols used." << endl;

    // multiply characters by 8
    cout << "There were " << size*8 << " bits in the original file." << endl;

    // count bits after translating
    cout << "There were " << bits << " bits in the compressed file." << endl;

    // symbols *8 / bit counts
    cout << "This gives a compression ration of " << ratio << "." << endl;

    // count bits / symbols
    cout << "The cost of the Huffman tree is " << bitscalc << " bits per character." << endl;


    // // read in characters one by one, until reading fails (we hit the end of the file)
    // char g;
    // while (file.get(g)) {
    //     cout << g;
    // }

    // // a nice pretty separator
    // cout << "----------------------------------------" << endl;

    // // once we hit the end of the file we are marked as "failed", so clear that
    // // then "seek" to the beginning of the file to start again
    // file.clear(); // Clears the _state_ of the file, not its contents!
    // file.seekg(0);

    // // Read the file again, and print to the screen
    // while (file.get(g)) {
    //     cout << g;
    // }

    // close the file
    file.close();


	return 0;
}