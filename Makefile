OBJS	= myshell.o param.o parse.o
SOURCE	= myshell.cpp param.cpp parse.cpp
HEADER	= myshell.hpp param.hpp parse.hpp
OUT	= myshell
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

myshell.o: myshell.cpp
	$(CC) $(FLAGS) myshell.cpp 

param.o: param.cpp
	$(CC) $(FLAGS) param.cpp 

parse.o: parse.cpp
	$(CC) $(FLAGS) parse.cpp 

clean:
	rm -f $(OBJS) $(OUT)