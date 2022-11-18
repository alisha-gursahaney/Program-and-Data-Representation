/*
 * Filename: PostfixCalculator.h
 * Description: PostfixCalculator class definition
 */

// Alisha Meena Gursahaney amg9zd
// Lab 3

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"

#include <iostream>
using namespace std;

class PostfixCalculator {
public:
	stack *x; // create new stack of type int

	// The default constructor
	PostfixCalculator();

	// addition method
	void addition();

	// subtraction method
	void subtraction();

	// multiplication method
	void multiplication();

	// division method
	void division();

	// negation method
	void negation();

	// empty method
	bool ifEmpty();

}; 

#endif
