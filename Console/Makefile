CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = tree
TEST_TARGET = test_tree
OBJS = main.o
TEST_OBJS = test_tree.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp Tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test_tree.o: test_tree.cpp Tree.hpp Complex.hpp doctest.h
	$(CXX) $(CXXFLAGS) -c test_tree.cpp

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJS)
