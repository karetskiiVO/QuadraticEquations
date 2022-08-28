#the compiler
CC = g++
 
#flags:
CFLAGS  = -g -Wall
 
#sources of input
SOURCES = main.cpp  QuadricSolver.cpp  QuadricTest.cpp  printfColored.cpp  arg.cpp

#sources of output
EXECUTABLE = calc

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm
