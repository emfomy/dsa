CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGETS = ../3_4_2.out

OBJECTS = \
	src/hw3_2.o \

HEADERS = \
	src/hw3_2.hpp \

all: $(TARGETS)

$(TARGETS): $(OBJECTS) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -c $(OPTFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) $(OBJECTS)
