// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

// Alisha Meena Gursahaney
// amg9zd
// Prelab 5

#include "TreeCalc.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    cleanTree(expressionStack.top()); // call delete tree on top value to destruct and free memory
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree != NULL) {
        // recurse on left child
        cleanTree(tree -> left);
        // recurse on right child
        cleanTree(tree -> right);
        delete tree;
    }
    else {
        delete tree;
    }
    //     if (tree->left != NULL) {
    //         cleanTree(tree->left); // call recursion on left child before deleting
    //         }
    //     else if (tree->right != NULL) {
    //         cleanTree(tree->right); // call recursion on right child before deleting
    //         }
    //     delete tree; // delete the tree to free memory
    // }
    // else {
    //     ; // if tree is already empty, do nothing
    // }

}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree

    TreeNode *node = new TreeNode(val);

    // while (!tree.empty()) {
    if (val.length() == 1) {
        if (val == "+" || val == "/" || val == "*" || val == "-") { // check if string stored is an operator
     // if (val.length() <= 1 && !isdigit(val[0])) {  
            TreeNode* right = expressionStack.top(); // store top value as a node
            expressionStack.pop(); // pop/remove this node
            TreeNode* left = expressionStack.top(); // store the new top value as a new node
            expressionStack.pop(); // pop/remove this node

        // if(node -> left != NULL) {
        //     expressionStack.push(node);
        // }
        //else {
            node -> left = left;
        //}

        // if (node -> right != NULL) {
            //expressionStack.push(node);
        //}
        // else {
            node -> right = right;
        //}
        }
    }
    expressionStack.push(node);
    // delete (node);

}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format

    // from Wikipedia pseudocode
    // no parenthesis required
    if (tree != NULL) {
        cout << tree -> value << " "; // print value plus space
        if (tree -> left != NULL) {
            printPrefix(tree -> left);  // recursive for left child
        }
        if (tree -> right != NULL) {
            printPrefix(tree ->right);  // recurisve for right child
        }
    }
    // base case if tree is empty
    else {
        return; // if tree is empty, do nothing
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses

    // from Wikipedia pseudocode
    // string x = tree->value; // in order to look at separate elements
    // paranthesis required
    if (tree != NULL) {
        // attempted to take formatting from remove to see if the value was an operator
        // if (x[0] == "+" || x[0] == "-" || x[0] == "*" || x[0] == "/") {
        if (tree -> left != NULL) {
            cout << "("; // print open parenthesis if tree token is operator
        // }
            printInfix(tree->left); // recursive for left child
        }

        cout << " " << tree -> value << " "; // print operator and spaces on each side

        if (tree -> right != NULL) {
            printInfix(tree->right); // recursive for right child

        // if (x[0] == "+" || x[0] == "-" || x[0] == "*" || x[0] == "/") {
            cout << ")";    // print close parenthesis if tree token is operator
        }

    }
    // base case if tree is empty
    else {
        return; // if tree is empty, do nothing
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form

    // from Wikipedia pseudocode
    // no paranthesis required
    if (tree != NULL) {
        if (tree-> left != NULL) {
            printPostfix(tree -> left); // recursive for left child
        }
        if (tree -> right != NULL) {
            printPostfix(tree -> right);    // recursive for right child
        }
        cout << tree -> value << " "; // print operator plus a space on the right side
    }
    // base case if tree is empty
    else {
        return;
    }

}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result

    // hard code each operator to calculate it
    if (tree->value == "+") {
        return (calculate(tree->left) + calculate(tree->right));
    }
    else if (tree->value == "-") {
        return (calculate(tree->left) - calculate(tree->right));
        // add if length is 1 or digit because negative numbers are not operators
    }
    else if (tree->value == "*") {
        return (calculate(tree->left) * calculate(tree->right));
    }
    else if (tree->value == "/") {
        return (calculate(tree->left) / calculate(tree->right));
    }

    else {
        return atoi((tree->value).c_str());
    }

}


//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    TreeNode* top = expressionStack.top();
    return calculate(top);
}
