CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include

SRCS = src/turnstile_cpu.cpp src/passenger_queue.cpp src/refund_stack.cpp src/turnstile_controller.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = transit_gate

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
