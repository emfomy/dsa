CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

TARGET = demo

OBJS = \
	src/hw2_4.o \
	src/line.o \
	src/property.o \
	src/unode_root.o \
	src/unode_user_id.o \
	src/unode_ad_id.o \
	src/unode_query_id.o \
	src/unode_position.o \
	src/unode_depth.o \
	src/anode_root.o \
	src/anode_ad_id.o \
	src/anode_property.o \
	src/anode_user_id.o \

HEADERS = \
	src/hw2.hh \
	src/hw2_4.hh \
	src/line.hh \
	src/property.hh \
	src/unode_root.hh \
	src/unode_user_id.hh \
	src/unode_ad_id.hh \
	src/unode_query_id.hh \
	src/unode_position.hh \
	src/unode_depth.hh \
	src/anode_root.hh \
	src/anode_ad_id.hh \
	src/anode_property.hh \
	src/anode_user_id.hh \

all: $(TARGET)

$(TARGET): $(OBJS) $(HEADERS)
	$(CC) $(OPTFLAGS) $(OBJS) -o $@

%.o: %.cc $(HEADERS)
	$(CC) -c $(OPTFLAGS) $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS)

run:
	./$(TARGET)
