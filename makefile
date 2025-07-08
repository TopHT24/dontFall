

CXX := g++
CXXFLAGS := -g -std=c++17 -Wall -Wextra -Iinclude

# Find all .cpp files inside src/
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)

TARGET := game.exe

# Raylib and required Windows libraries
LIBS := -lraylib -lwinmm -lgdi32

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compile each .cpp into a .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)



.PHONY: all clean
