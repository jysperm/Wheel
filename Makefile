all:
	make -C array+
	make -C array
	make -C linklist
test: all
	./array+/test
	./array/test
	./linklist/test

