CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -fsanitize=address
LDFLAGS = -fsanitize=address
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = revelation.out
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
