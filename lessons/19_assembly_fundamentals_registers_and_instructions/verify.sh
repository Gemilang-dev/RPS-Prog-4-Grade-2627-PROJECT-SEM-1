#!/usr/bin/env bash
echo "[TEST] Verifying Assembly Fundamentals: Registers & Instructions..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 19_assembly_fundamentals_registers_and_instructions verified successfully!"
