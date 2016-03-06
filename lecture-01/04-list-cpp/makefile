testlist: testlist.o list.o
	g++ -g $^ -o $@

list.o: list.cpp list.h
	g++ -g -c -Wall -pedantic $< -o $@

testlist.o: testlist.cpp list.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm list.o testlist.o testlist