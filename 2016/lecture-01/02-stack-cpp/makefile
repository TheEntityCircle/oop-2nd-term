teststack: teststack.o stack.o
	g++ -g $^ -o $@

stack.o: stack.cpp stack.h
	g++ -g -c -Wall -pedantic $< -o $@

teststack.o: teststack.cpp stack.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm stack.o teststack.o teststack