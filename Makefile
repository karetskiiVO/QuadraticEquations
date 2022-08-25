#the compiler
CC = g++
 
#flags:
CFLAGS  = -g -Wall
 
#sources of input
SOURCES = main.cpp  QuadricSolver.cpp QuadricTest.cpp

#sources of output
EXECUTABLE = calc

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm
debug:
	$(CC) $(SOURCES) $(CFLAGS) -D debugMode -MD -o $(EXECUTABLE) -lm