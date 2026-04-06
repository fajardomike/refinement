CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp game.cpp puzzle.cpp puzzlebank.cpp player.cpp \
       mathpuzzle.cpp wordpuzzle.cpp sciencepuzzle.cpp \
       messages.cpp display.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = refinement

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
