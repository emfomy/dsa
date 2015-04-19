CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGETS = hw3_1

OBJECTS = \
	src/hw3_1.o \

HEADERS = \
	src/hw3_1.hpp \

all: $(TARGETS)

$(TARGETS): $(OBJECTS) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -c $(OPTFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) $(OBJECTS)
