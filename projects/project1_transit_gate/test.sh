#!/usr/bin/env bash
set -e

echo "=================================================="
echo "  PROJECT 1: TRANSIT GATE COMPILATION & TEST"
echo "=================================================="

echo -e "\n[1/3] Compiling Project 1 Main Binary..."
g++ -Wall -Wextra -std=c++17 -I./include \
    src/turnstile_cpu.cpp \
    src/passenger_queue.cpp \
    src/refund_stack.cpp \
    src/turnstile_controller.cpp \
    src/main.cpp \
    -o transit_gate

echo -e "\n[2/3] Compiling Automated Self-Test Runner..."
g++ -Wall -Wextra -std=c++17 -I./include \
    src/turnstile_cpu.cpp \
    src/passenger_queue.cpp \
    src/refund_stack.cpp \
    src/test_runner.cpp \
    -o test_suite

echo -e "\n[3/3] Running Automated Self-Tests:"
./test_suite

echo -e "\n--- Simulation Output Sample: ---"
./transit_gate
