# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -fsanitize=address

TARGET = revelation.out
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
