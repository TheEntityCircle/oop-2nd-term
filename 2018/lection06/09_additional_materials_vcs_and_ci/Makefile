all: compile
	g++ main.o dice.o -o main

compile:
	g++ -c *.cpp

tests: compile
	g++ -c tests.cpp
	g++ tests.o dice.o -lboost_unit_test_framework -o tests

run-tests: tests
	./tests

clean:
	rm -f *.o main tests
