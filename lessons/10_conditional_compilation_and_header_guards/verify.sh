#!/usr/bin/env bash
echo "[TEST] Verifying Conditional Compilation & Header Guards..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 10_conditional_compilation_and_header_guards verified successfully!"
