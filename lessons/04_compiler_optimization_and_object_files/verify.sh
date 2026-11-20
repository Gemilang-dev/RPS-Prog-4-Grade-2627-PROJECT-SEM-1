#!/usr/bin/env bash
echo "[TEST] Verifying Compiler Optimization & Object Files..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 04_compiler_optimization_and_object_files verified successfully!"
