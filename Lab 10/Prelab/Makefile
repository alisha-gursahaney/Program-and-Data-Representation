# Alisha Meena Gursahaney
# prelab 10
# amg9zd

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2# Enable all warnings
DEBUG=-g
# TARGET=a.out

a.out: heap.o heapNode.o huffmanenc.o
	$(CXX) heap.o heapNode.o huffmanenc.o -o a.out

heap.o: heap.h heap.cpp

huffmanenc.o: huffmanenc.cpp

heapNode.o: heapNode.h heapNode.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out