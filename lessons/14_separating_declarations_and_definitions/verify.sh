#!/usr/bin/env bash
echo "[TEST] Verifying Separating Declarations (.h) & Definitions (.cpp)..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 14_separating_declarations_and_definitions verified successfully!"
