CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGETS  = system

.PHONY: all clean

OBJECTS  = \
	src/system.o

HEADERS  = \
	src/binomial_heap.hpp \
	src/computer.hpp \
	src/task.hpp

all: $(TARGETS)

system: $(OBJECTS) $(HEADERS)
	$(CC) -fno-strict-aliasing $(OPTFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -fno-strict-aliasing $(OPTFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGETS) $(OBJECTS)
