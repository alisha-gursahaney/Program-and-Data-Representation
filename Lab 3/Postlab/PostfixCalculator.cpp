#include <iostream>
#include "PostfixCalculator.h"
#include "stack.h"

// using namespace std;

// Alisha Meena Gursahaney amg9zd
// Lab 3

//Constructor - no return type
PostfixCalculator::PostfixCalculator() {
	x = new stack(); // create new stack of type int
	//new stack
}

// how to reference stack methods here?

// add 2 elements of stack and push sum onto stack
void PostfixCalculator::addition() {
	int number1 = x -> top(); 			// take first int in stack and save as variable
	x -> pop(); 						// delete number1 in stack and move next integer to top
	int number2 = x -> top(); 			// save top int as variable
	x -> pop(); 						// delete top of stack to move the rest up 1
	int sum = number1 + number2; 	// add the 2 integers together
	x -> push(sum); 					// add the sum onto the stack
}

// subtract 2 elements of stack and push difference onto stack
void PostfixCalculator::subtraction() {
	int number1 = x -> top(); 			// take first int in stack and save as variable
	x -> pop(); 						// delete top of stack and move up 1
	int number2 = x -> top();			 // save new first int as variable
	x -> pop(); 						// delete top element of stack
	int diff = number2 - number1; 	// subtract the 2 elements
	x -> push(diff); 					// add this new value to the stack
}

// multiply 2 elements of stack and push product onto stack
void PostfixCalculator::multiplication() {
	int number1 = x -> top(); 			// take first int in stack and save as variable
	x -> pop(); 						// delete top of stack and move up 1
	int number2 = x -> top(); 			// save new first int as variable
	x -> pop(); 						// delete top element of stack
	int prod = number1 * number2; 	// multiply the 2 elements
	x -> push(prod); 					// add this new value to the stack
}

// divide 2 elements of stack and push value onto stack
void PostfixCalculator::division() {
	int number1 = x -> top(); 			// take first int in stack and save as variable
	x -> pop(); 						// delete top of stack and move up 1
	int number2 = x -> top(); 			// save new first int as variable
	x -> pop(); 						// delete top element of stack
	int div = number2 / number1; 	// divide the 2 elements
	x -> push(div); 					// add this new value to the stack
}

// negate the integer
void PostfixCalculator::negation() {
	int number1 = x -> top();			// take first int in stack and save as variable
	x -> pop();						// delete top of stack and move up 1
	int negate = number1 * (-1);	// negate this integer by multiplying by -1
	x -> push(negate);					// add this new value onto the stack
	// FIX THIS: outputting 1D <- not sure what the D is
}


// check if stack is empty and return bool
bool PostfixCalculator::ifEmpty() {
	if (x -> empty()) {
		return true;	// stack is empty
	}
	else {
		return false;
	}
}

