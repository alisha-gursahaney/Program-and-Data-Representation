#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    nodes = 0;
    // added to keep track of size
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
    nodes = 0; // added to keep track of size
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    // BinaryNode *insert = new BinaryNode(x);
    // call the private method
    // parameters: root is the node and x is the string value
    if (!find(x)) {
        insert(root, x); // do nothing
         // no return because method is void
    }
    else {
        insert(root, x); 
    }
    nodes++;
}

// private helper method
void BinarySearchTree::insert(BinaryNode*& node , const string& x) {
    // from BST:insert in lecture slides
    if (node == NULL) {
        node = new BinaryNode();
        node -> value = x; // not from slides, but added to make the new nodes value x
    }
    else if (x < node -> value) { // less than in binary tree will mean it must go left of the current node
        insert(node->left, x); // recursive with left node
    }
    else if (x > node -> value) { // greater than in binary tree will mean it must go right of the current node
        insert(node -> right, x); // recursive with right node
    }
    else {
        ;   // duplicate... do nothing
    }


}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
    nodes--;
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    // BinaryNode *path = new BinaryNode();
    if (!find(x)) {
        return " ";
    }
    else {
        return pathTo(root, x);
    }
    

}
// private helper for pathto
string BinarySearchTree::pathTo(BinaryNode* path, const string& x) const{
    // BinaryNode* path = new BinaryNode();

    if (path->value == x) {
        return x;
    }
    else if (x < path -> value) {
        // cout << path -> left << " ";
        return path -> value + " " + pathTo(path->left, x);
    }
    else if (x > path -> value) {
        // cout << path -> right << " ";
        return path -> value + " " + pathTo(path -> right, x);
    }

    else{
        return " ";
    }
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    // BinaryNode *find = new BinaryNode();
    // find = root;
    return find(root, x);
    
}

// private helper for find
bool BinarySearchTree::find(BinaryNode* node, const string& x) const{
// help from BST:find slides
    if (node != NULL) {
        if (node -> value == x) {
            return true;
        }
        else if (x < node -> value) {
            return find(node->left, x); // recursion for left node

        }
        else if (x > node ->value) {
            return find(node->right, x); // recursion for right node
        }
    }
    else if (node == NULL) {
        return false; // if gone through all nodes and did not find, return false
    }
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    return nodes; // returns the variable that has been keeping track of the nodes at insert and remove
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}
