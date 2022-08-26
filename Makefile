TARGET := calc
PREFIX := /release

.PHONY: all clean default

all: default

#the compiler
CC := g++

#flags:
CFLAGS  := -g -Wall#-Md --coverage
 
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
#

default:
	$(CC) $(CFLAGS) -MD -o $^ -lm 
#

debug:
	$(CC) $(CFLAGS) -D debugMode -MD -o $^ -lm
#cleane  .PHONY buildDirectory -include *.d
#:= -immeditly = -in time

#check headers
-include *.d

clean: 
	rm -rf *.o *.d