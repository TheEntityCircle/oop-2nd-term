CXX := g++
CXXFLAGS := -Wall -std=c++11 -fno-elide-constructors

OBJS := $(patsubst %.cpp,%,$(wildcard *.cpp))

all: $(OBJS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: all clean
