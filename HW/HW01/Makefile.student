# CSCI3081 HW01 makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o point2.o
	$(CC) $(LFLAGS) point2.o main.o -o hw01.out

point2.o : point2.cc
	$(CC) $(CFLAGS) point2.cc
	
main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o hw01.out