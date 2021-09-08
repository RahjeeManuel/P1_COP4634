CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: /*testFilesNames*/

clean:
        rm -rf *dSYM
        $(RM) *.o *.gc* test/*.o core main
testFileName: $(OBJECTS) //header and source code files
        $(CXX) $(CXXFLAGS) -o $@ $^