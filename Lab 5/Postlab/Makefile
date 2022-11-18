# Alisha Meena Gursahaney
# inlab 5
# amg9zd

# copied makefiles from prelab and inlab and changed file names

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
# TARGET=a.out

a.out: AVLTree.o AVLNode.o AVLPathTest.o
	$(CXX) $(DEBUG) AVLTree.o AVLNode.o AVLPathTest.o -o a.out

AVLTree.o: AVLTree.h AVLTree.cpp

AVLNode.o: AVLNode.h AVLNode.cpp 

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLTree.cpp AVLNode.h AVLNode.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
