CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lboost_unit_test_framework

SOURCES=dice.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: app tests

app: $(OBJECTS) main.o
	$(CC) $(OBJECTS) main.o -o $@ $(LDFLAGS)

tests: $(OBJECTS) tests.o
	$(CC) $(OBJECTS) tests.o -o $@ $(LDFLAGS)

run-tests: tests
	./tests

.cpp.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o tests app
