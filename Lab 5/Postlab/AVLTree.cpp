#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
    count = 0; // initialize count size
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
    count = 0; // keep track of size
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    // same as inlab BST insert with some minor changes
    count++;
    // height(x) += 1;
    if (!find(x)) {
        //insert(root, x); // do nothing
         // no return because method is void
    }
    else {
        insert(root, x); 
    }
}

// private helper method
void AVLTree::insert(AVLNode*& node , const string& x) {
    // from BST:insert in lecture slides
    // update height
    // of new node
    // balance tree
    if (node == NULL) {
        node = new AVLNode();
        node -> value = x; // not from slides, but added to make the new nodes value x
    }
    else if (x < node -> value) { // less than in binary tree will mean it must go left of the current node
        insert(node->left, x); // recursive with left node
    }
    else if (x > node -> value) { // greater than in binary tree will mean it must go right of the current node
        insert(node -> right, x); // recursive with right node
    }
    node->height = 1 + max(height(node->left), height(node->right));
    // 1 greater than height of children
    balance(node);
    //else {
      //  ;   // duplicate... do nothing
    //}

}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    count--; // added to keep track of size
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE

if (!find(x)) {
        return " ";
    }
    else {
        return pathTo(root, x);
    }
    

}
// private helper for pathto
string AVLTree::pathTo(AVLNode* path, const string& x) const{
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
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    // same as inlab BST find method (copy and pasted)
    return find(root, x);
    
}

// private helper for find
bool AVLTree::find(AVLNode* node, const string& x) const{
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
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    // keep track with variable count
    return count;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    // pseudocode in directions
    int r_height = height(n->right);
    int l_height = height(n->left);
    int balancefactor = r_height - l_height; // Note that balance factor here is assumed to be (height of right subtree - height of left subtree)

    if (balancefactor== 2) { // if balance factor of node is 2 we will need to rotate left:
        int rr = height(n->right->right);
        int rl = height(n->right->left);
        int rightbf = rr - rl; 
        // first, see if we should also rotate right (i.e., do a double rotation), 
        // if balance factor of right child is negative:
        if (rightbf < 0) { // check if we need to rotate right -> if balance factor is negative
            n->right = rotateRight(n->right); // rotate right on right child
        }
        n=rotateLeft(n); // rotate left on node
    }
    else if (balancefactor == -2) { // if balance factor is -2, we need to rotate right:
        int lr = height(n->left->right);
        int ll = height(n->left->left);
        int leftbf = lr - ll; 
        // first need to see if we need to rotate left
        if (leftbf > 0) { // if balance factor of left child is positive, we need to rotate left
            n -> left = rotateLeft(n->left); // rotate left on the left child
        }
        n = rotateRight(n); // rotate right on the node
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* node2 = new AVLNode();
    node2 = n -> right;
    n = node2 -> left;
    balance(n);
        return n;
    
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* node2 = new AVLNode();
    node2 = n->left;
    n = node2 -> right;
    balance(n);
    n->height = 1 + max(height(n->left), height(n->right));
        return n;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
