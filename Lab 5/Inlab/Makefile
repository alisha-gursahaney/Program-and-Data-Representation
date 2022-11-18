
# Alisha Meena Gursahaney
# inlab 5
# amg9zd


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
# TARGET=a.out

a.out: BinarySearchTree.o BinaryNode.o BSTPathTest.o
	$(CXX) $(DEBUG) BinarySearchTree.o BinaryNode.o BSTPathTest.o -o a.out

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp

BinaryNode.o: BinaryNode.h BinaryNode.cpp 

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinarySearchTree.cpp BinaryNode.h BinaryNode.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
