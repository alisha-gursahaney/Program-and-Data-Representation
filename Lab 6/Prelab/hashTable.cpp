// Alisha Meena Gursahaney
// amg9zd
// prelab 6

#include "hashTable.h"
// #include <string>

// using namespace std;

// used google to help with creating hashtable

// copied functions from primenumber.cpp
bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

// constructor
hashTable::hashTable(int dictionarysize) {
	// should be larger than the dictionary size and be a prime number
	// use get prime number to get a larger number than the size that is also prime
	// int size = dictionarysize *2;
	// lecture slides said to do size x 2
	int size;
	if (!checkprime(dictionarysize *2)) {
		// size is not prime and cannot be used to create hash
		size = getNextPrime(dictionarysize *2);
	}
	else {
		// size is already prime and can be used to create a hash
		size = dictionarysize*2;
	}

	// initialize bucket
	bucket = new vector<list<string> >;

	for(int i = 0; i < size; i++) {
		list<string> templist;
		bucket->push_back(templist);
	}

	//hasht = new list<string>[size];

	//bucket->push_back(hasht);
}

// destructor
hashTable::~hashTable() {
	// delete
	delete bucket;
}


// helper method for insert in order to find key location to place
int hashTable::hashKey(string s) {
	// find prime number greater than max word length
	int key = getNextPrime(22);
	// prime number makes it faster
	//int key = 0;
	for (int i = 0; i < s.length(); i++) {
		key += s[i];
	}
	return key;
	
}


// add linear probing somewhere

// inserts a string into the hash table and returns nothing (void)
void hashTable::insert(string s){
	// % the key by the bucket size
	int keyinsert = hashKey(s) % bucket->size();
	bucket->at(keyinsert).push_back(s);
}

		
// returns true if string is found in hash table
// returns a string of whatever determines if a word exists in the hash table
// to see if the word is in the dictionary
// returns a string or blank string if it is not in the dictionary
// could be used as bool
// could do string
// string hashtable returns the found word
bool hashTable::search(string x){
	
	int keynum = hashKey(x);
	// while there is a value
	// while (hasht[keynum] != "") {
	// 	if (hasht[keynum] == x) {
	// 		// if the value equals the string x we are searching for, return true
	// 		return true;
	// 	}
	// 	// iterate through by adding to this integer while its not null
	// 	keynum++;
	// }

	// if string length is greater than max word length, return false
	// if (x.length() > 22 ) {
	// 	return false;
	// }

	// // if the value is nothing, return false
	// else if (hasht[keynum] == "") {
	// 	return false;
	// }
	// all other possibilities

	// bucket at the key using the helper function

	list<string> & searchlist = bucket->at(keynum);
	// create iterator for list
	// go from beginning to end
	// if the parameter string matches the pointer iterator, then the word is found and returns true/ the string
	// begin and end used for list for loop
	for (list<string>::iterator i = searchlist.begin(); i != searchlist.end(); i++) {
		if (x == *i) {
			return true;
			// return x;
		}
	}

	return false;
	// return "";
}







