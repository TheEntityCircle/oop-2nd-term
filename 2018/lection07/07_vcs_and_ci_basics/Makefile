CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lboost_unit_test_framework

SOURCES=dice.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: app tests

app: $(OBJECTS) main.o
	$(CC) $(LDFLAGS) $(OBJECTS) main.o -o $@

tests: $(OBJECTS) tests.o
	$(CC) $(LDFLAGS) $(OBJECTS) tests.o -o $@

run-tests: tests
	./tests

.cpp.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o tests app
