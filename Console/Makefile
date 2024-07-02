# Makefile
# Email: your_email@example.com

CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = tree
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp Tree.h Complex.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) $(OBJS)
