CC       = g++
OPTFLAGS = -O2 -std=c++11 -Wall

SUBDIRS = hw3_1 hw3_2

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

run1:
	./3_4_1.out < ./input > ./output

run2:
	./3_4_2.out < ./input > ./output
