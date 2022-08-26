.PHONY: all clean release

SOURCES := main.cpp  QuadricSolver.cpp QuadricTest.cpp printfColored.cpp
OBJ = $(SOURCES:.cpp=.o)

all: release

#the compiler
CC := g++
SRC = main.cpp 

#flags:
CFLAGS  := -g -Wall#-Md --coverage
 
%.o: %.cpp
	$(CC) -c $(CFLAGS) $<  
#

release: $(OBJ)
	$(CC) $(CFLAGS) -MD $^ -o $@ -lm 
#

check:
	@echo $(OBJ)

debug: $(OBJ)
	$(CC) $(CFLAGS) -D debugMode -MD -o $^ -lm
#cleane  .PHONY buildDirectory -include *.d
#:= -immeditly = -in time

#check headers
-include *.d

clean: 
	rm -rf *.o *.d

#########################