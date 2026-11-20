CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include

SRCS = src/vitals_cpu.cpp src/er_queue.cpp src/action_stack.cpp src/triage_controller.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = hospital_triage

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
