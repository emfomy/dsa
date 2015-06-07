SOURCES1 = \
	src/hw6_2.cpp

SOURCES2 = \
	src/hw6_3.cpp

HEADERS1 = \

HEADERS2 = \

hw6_2.o: $(SOURCES1) $(HEADERS1)
	$(CXX) $(CXXFLAGS) -c $(SOURCES1) -o $@

hw6_3.o: $(SOURCES2) $(HEADERS2)
	$(CXX) $(CXXFLAGS) -c $(SOURCES2) -o $@
