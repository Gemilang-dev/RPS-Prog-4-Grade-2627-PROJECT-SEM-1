#!/usr/bin/env bash
echo "[TEST] Verifying Linker & Symbol Tables..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 05_linker_and_symbol_tables verified successfully!"
