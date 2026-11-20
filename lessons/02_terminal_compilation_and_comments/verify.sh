#!/usr/bin/env bash
echo "[TEST] Verifying C++ Terminal Compilation, Flags & Comment Anatomy..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 02_terminal_compilation_and_comments verified successfully!"
