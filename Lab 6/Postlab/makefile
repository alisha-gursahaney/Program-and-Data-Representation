# Alisha Meena Gursahaney
# prelab 6
# amg9zd


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2# Enable all warnings
DEBUG=-g
# TARGET=a.out

a.out: hashTable.o wordPuzzle.o timer.o
	$(CXX) hashTable.o wordPuzzle.o timer.o -o a.out

hashTable.o: hashTable.h hashTable.cpp

wordPuzzle.o: wordPuzzle.cpp

timer.o: timer.h timer.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
