all: test

test: test.o array.o
	gcc -o test test.o array.o

array.o: array.c array.h
	gcc -c array.c

test.o: test.c
	gcc -c test.c

clean:
	rm test test.o array.o
