CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGETS  = system

.PHONY: all clean

OBJECTS  = \
	src/system.o \

HEADERS  = \
	src/binomial_heap.hpp \

all: $(TARGETS)

system: $(OBJECTS) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -c $(OPTFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) $(OBJECTS)
