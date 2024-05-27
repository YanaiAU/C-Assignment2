CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion

TEST_OBJS = Graph.o Algorithms.o Test.o
TEST_COUNTER_OBJS = Graph.o Algorithms.o TestCounter.o

all: test testCounter

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o test $(TEST_OBJS) -lstdc++

testCounter: $(TEST_COUNTER_OBJS)
	$(CXX) $(CXXFLAGS) -o testCounter $(TEST_COUNTER_OBJS) -lstdc++

Graph.o: Graph.cpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp

Algorithms.o: Algorithms.cpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp

Test.o: Test.cpp
	$(CXX) $(CXXFLAGS) -c Test.cpp

TestCounter.o: TestCounter.cpp
	$(CXX) $(CXXFLAGS) -c TestCounter.cpp

clean:
	rm -f *.o test testCounter
