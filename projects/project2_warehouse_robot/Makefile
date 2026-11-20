CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include

SRCS = src/robot_alu.cpp src/conveyor_fifo.cpp src/pallet_lifo.cpp src/dispatcher_controller.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = warehouse_robot

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
