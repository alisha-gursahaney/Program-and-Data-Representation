# Makefile for CS 2150 prelab9
# This Makefile shows how to link assembly with C/C++
# Taken from vecsum makefile and altered
# Alisha Meena Gursahaney
# amg9zd

# Defines the C++ compiler we'll be using
CXX = clang

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g


OBJECTS = linkedlist.o 
# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

# All of the .o files for our program
linkedlist.o: linkedlist.c

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~
