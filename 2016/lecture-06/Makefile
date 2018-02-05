CXX := g++
CXXFLAGS := -Wall -std=c++11

OBJS := $(patsubst %.cpp,%,$(wildcard *.cpp))

all: $(OBJS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS) capacity.txt

run_auto: auto
	./auto | c++filt -t

.PHONY: all clean run_auto
