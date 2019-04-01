EXEFILE = MyDuckApplication
# names our executable
CXXFLAGS = -c -Wall
# sets flags for g++ compiler

# target: dependencies
# [tab]command

# The two below were replaced with the target below: See line 133 README
# Duck.o: Duck.h Duck.cpp
# 	g++ -c Duck.cpp
#
# DecoyDuck.o: Duck.h DecoyDuck.h DecoyDuck.cpp
# 	g++ -c DecoyDuck.cpp
$(EXEFILE): Duck.o MallardDuck.o DecoyDuck.o RubberDuck.o QuackBehavior.o MuteQuack.o Quack.o Squeak.o main.o
	g++ $^ -o $@

%.o: %.cpp
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o $(EXEFILE)
.PHONY: clean
