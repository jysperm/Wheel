all: test

test: test.o linklist.o
	g++ -o test test.o linklist.o

linklist.o: linklist.c linklist.h
	gcc -c linklist.c

test.o: test.c
	g++ -c test.c

clean:
	rm test test.o linklist.o
