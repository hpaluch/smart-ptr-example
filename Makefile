CXXFLAGS = -g -Wall
LDFLAGS  = -g
LDLIBS   = -lboost_system

all : main

main : main.o

main.o : main.cpp

run : main
	./main

.PHONY: clean
clean:
	rm -f main *.o

.PHONY: valgrind
valgrind: main
	valgrind ./main
