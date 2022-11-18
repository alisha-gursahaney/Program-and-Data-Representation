#include <iostream>
#include "PostfixCalculator.h"
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;

// Alisha Meena Gursahaney amg9zd
// Lab 3

int main () {
PostfixCalculator object;

string user;
while (cin >> user) {

    if (user == "+") {
    	if (object.ifEmpty()) {
    		exit(-1); // terminate when empty
    		}
    	object.addition();
    	}

    else if (user == "-" and user.length() == 1) {
    	if (object.ifEmpty()) {
    		exit(-1); // terminate when empty
    		}
    	object.subtraction();
    	}

    else if (user == "*") {
        if (object.ifEmpty()) {
            exit(-1); // terminate when empty
            }
        object.multiplication();
    } 

    else if (user == "/") {
        if (object.ifEmpty()) {
            exit(-1); // terminate when empty
            }
        object.division();
    } 

    else if (user == "~") {
        if (object.ifEmpty()) {
            exit(-1); // terminate when empty
            }
        object.negation();
    }

    // else if (user == "-" and user.length() > 1) {
        // int temp = std::stoi(user)
    // }

    else {
    	// convert string to integer
    	int temp = std::stoi(user);
    	object.x.push(temp);
    	}
   	}

   	// outside of while
    cout << object.x.top() << endl;

}
