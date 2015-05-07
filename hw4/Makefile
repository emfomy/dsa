CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGETS  = tree forest

OBJECTS1 = \
	src/hw4_1.o \
	src/sample.o \

OBJECTS2 = \
	src/hw4_2.o \

HEADERS  = \
	src/hw4.hpp \
	src/sample.hpp \

all: $(TARGETS)

tree: $(OBJECTS1) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS1) -o $@

forest: $(OBJECTS2) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS2) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -c $(OPTFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) $(OBJECTS1) $(OBJECTS2)
