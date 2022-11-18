// Alisha Meena Gursahaney
// amg9zd
// prelab 6


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class hashTable {
	public:
		// constructor and copy constructor ??
		// hashTable();

		// constructor
		hashTable(int dictionarysize);

		// destructor
		~hashTable();

		// insert into hash table
		void insert(string s);

		// find in the hash table
		bool search(string x);
		

	private:
		// from primenumber.cpp
		bool checkprime(unsigned int p);
		int getNextPrime(unsigned int n);
		//int size;

		// helper method for insert
		int hashKey(string s);

		// use vectors for buckets
		// buckets being multiple values for same key in hash table
		// then use this linked list in linear probing to make sure 1 value for each key
		vector <list <string> >* bucket;
};

#endif