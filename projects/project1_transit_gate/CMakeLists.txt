cmake_minimum_required(VERSION 3.16)
project(project1_transit_gate CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Main executable simulation
add_executable(transit_gate
    src/turnstile_cpu.cpp
    src/passenger_queue.cpp
    src/refund_stack.cpp
    src/turnstile_controller.cpp
    src/main.cpp
)

# Automated self-test runner
add_executable(transit_test
    src/turnstile_cpu.cpp
    src/passenger_queue.cpp
    src/refund_stack.cpp
    src/test_runner.cpp
)
