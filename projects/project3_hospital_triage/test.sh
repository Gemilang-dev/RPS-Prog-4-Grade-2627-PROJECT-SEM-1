#!/usr/bin/env bash
set -e

echo "=================================================="
echo "  PROJECT 3: HOSPITAL TRIAGE COMPILATION & TEST"
echo "=================================================="

echo -e "\n[1/3] Compiling Project 3 Main Binary..."
g++ -Wall -Wextra -std=c++17 -I./include \
    src/vitals_cpu.cpp \
    src/er_queue.cpp \
    src/action_stack.cpp \
    src/triage_controller.cpp \
    src/main.cpp \
    -o triage_monitor

echo -e "\n[2/3] Compiling Automated Self-Test Runner..."
g++ -Wall -Wextra -std=c++17 -I./include \
    src/vitals_cpu.cpp \
    src/er_queue.cpp \
    src/action_stack.cpp \
    src/test_runner.cpp \
    -o test_suite

echo -e "\n[3/3] Running Automated Self-Tests:"
./test_suite

echo -e "\n--- Simulation Output Sample: ---"
./triage_monitor
