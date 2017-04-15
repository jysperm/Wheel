all: test

test: test.o linklist.o
	gcc -o test test.o linklist.o

linklist.o: linklist.c linklist.h
	gcc -c linklist.c

test.o: test.c
	gcc -c test.c

clean:
	rm test test.o linklist.o
