cmake_minimum_required(VERSION 3.16)
project(project2_warehouse_robot CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Main executable simulation
add_executable(warehouse_robot
    src/robot_alu.cpp
    src/conveyor_fifo.cpp
    src/pallet_lifo.cpp
    src/dispatcher_controller.cpp
    src/main.cpp
)

# Automated self-test runner
add_executable(robot_test
    src/robot_alu.cpp
    src/conveyor_fifo.cpp
    src/pallet_lifo.cpp
    src/test_runner.cpp
)
