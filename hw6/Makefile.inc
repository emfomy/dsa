OBJ1 += \

OBJ2 += \
	src/node.o

HEADERS1 = \

HEADERS2 = \
	src/node.hpp

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

hw6_2.o: src/hw6_2.cpp $(HEADERS1)
	$(CXX) $(CXXFLAGS) -c src/hw6_2.cpp -o $@

hw6_3.o: src/hw6_3.cpp $(HEADERS2)
	$(CXX) $(CXXFLAGS) -c src/hw6_3.cpp -o $@
