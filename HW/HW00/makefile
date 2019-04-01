# CSCI3081 HW00 makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o
	$(CC) $(LFLAGS) main.o -o HW00.out

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *.*~ HW00.out
