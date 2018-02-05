teststack: teststack.o stack.o
	gcc -g $^ -o $@

stack.o: stack.c stack.h
	gcc -c -g -Wall -pedantic $< -o $@

teststack.o: teststack.c stack.h
	gcc -c -g -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm stack.o teststack.o teststack