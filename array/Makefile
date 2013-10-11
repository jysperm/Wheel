all: test

test: test.o array.o
	g++ -o test test.o array.o

array.o: array.c array.h
	gcc -c array.c

test.o: test.c
	g++ -c test.c

clean:
	rm test test.o array.o
