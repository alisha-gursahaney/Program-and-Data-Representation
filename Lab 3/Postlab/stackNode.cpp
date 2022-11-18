#include <iostream>
#include "stackNode.h"

// Alisha Meena Gursahaney amg9zd
// post lab 3

// next line needed because NULL is part of std namespace
// using namespace std;

stackNode::stackNode() {
    next = NULL;
    previous = NULL;
    value = 0;
}