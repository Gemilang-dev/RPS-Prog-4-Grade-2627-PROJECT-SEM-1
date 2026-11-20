#!/usr/bin/env bash
echo "[TEST] Verifying OS Execution Model: Stack vs Heap..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 06_os_execution_model_stack_vs_heap verified successfully!"
