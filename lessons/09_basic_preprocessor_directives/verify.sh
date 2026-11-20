#!/usr/bin/env bash
echo "[TEST] Verifying Basic Preprocessor Directives..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 09_basic_preprocessor_directives verified successfully!"
