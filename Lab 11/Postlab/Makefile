# Taken from vecsum makefile and altered
# Alisha Meena Gursahaney
# postlab 11
# amg9zd

# Defines the C++ compiler we'll be using
CXX = clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g -std=c++20

# Defines the assembler
AS = nasm

# Defines the flags for the assembler
ASFLAGS = -f macho64 -g

# All of the .o files for our program
OBJECTS = puzzle.o
.SUFFIXES: .o .cpp

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~