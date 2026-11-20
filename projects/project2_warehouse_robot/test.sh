#!/usr/bin/env bash
set -e

echo "=================================================="
echo "  PROJECT 2: WAREHOUSE ROBOT COMPILATION & TEST"
echo "=================================================="

echo -e "\n[1/3] Compiling Project 2 Main Binary..."
g++ -Wall -Wextra -std=c++17 -I./include \
    src/robot_alu.cpp \
    src/conveyor_fifo.cpp \
    src/pallet_lifo.cpp \
    src/dispatcher_controller.cpp \
    src/main.cpp \
    -o warehouse_dispatcher

echo -e "\n[2/3] Compiling Automated Self-Test Runner..."
g++ -Wall -Wextra -std=c++17 -I./include \
    src/robot_alu.cpp \
    src/conveyor_fifo.cpp \
    src/pallet_lifo.cpp \
    src/test_runner.cpp \
    -o test_suite

echo -e "\n[3/3] Running Automated Self-Tests:"
./test_suite

echo -e "\n--- Simulation Output Sample: ---"
./warehouse_dispatcher
