CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGETS  = tree forest

.PHONY: all clean

OBJECTS  = \
	src/sample.o \
	src/sample_set.o \
	src/node.o \
	src/tree.o \

OBJECTS1 = \
	$(OBJECTS) \
	src/hw4_1.o \

OBJECTS2 = \
	$(OBJECTS) \
	src/hw4_2.o \
	src/forest.o \

HEADERS  = \
	src/hw4.hpp \
	src/sample.hpp \
	src/sample_set.hpp \
	src/node.hpp \
	src/tree.hpp \
	src/forest.hpp \

all: $(TARGETS)

tree: $(OBJECTS1) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS1) -o $@

forest: $(OBJECTS2) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS2) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -c $(OPTFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) $(OBJECTS1) $(OBJECTS2)
