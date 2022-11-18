
# Alisha Meena Gursahaney
# Prelab 5
# amg9zd


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
# TARGET=a.out

a.out: TreeCalc.o TreeNode.o TreeCalcTest.o
	$(CXX) $(DEBUG) TreeCalcTest.o TreeCalc.o TreeNode.o -o a.out

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.cpp TreeCalc.h TreeNode.h TreeNode.cpp

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
