all:
	make -C array+
	make -C array

test: all
	./array+/test
	./array/test

