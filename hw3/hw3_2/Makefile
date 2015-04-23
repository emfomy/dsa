CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGETS = ../3_4_2.out

OBJECTS = \
	src/hw3_2.o \
	src/token.o \
	src/token_queue.o \
	src/token_stack.o \
	src/shunting_yard.o \
	src/evaluate_postfix.o \

HEADERS = \
	src/hw3.hpp \
	src/token.hpp \
	src/token_queue.hpp \
	src/token_stack.hpp \
	src/shunting_yard.hpp \
	src/evaluate_postfix.hpp \

all: $(TARGETS)

$(TARGETS): $(OBJECTS) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -c $(OPTFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) $(OBJECTS)
