#!/usr/bin/env bash
echo "[TEST] Verifying Namespaces in C++..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 11_namespaces verified successfully!"
