# Alisha Meena Gursahaney
# inlab 10
# amg9zd

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2# Enable all warnings
DEBUG=-g
# TARGET=a.out

a.out: huffmandec.o
	$(CXX) huffmandec.o -o a.out

# heap.o: heap.h heap.cpp

huffmandec.o: huffmandec.cpp

#heapNode.o: heapNode.h heapNode.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out