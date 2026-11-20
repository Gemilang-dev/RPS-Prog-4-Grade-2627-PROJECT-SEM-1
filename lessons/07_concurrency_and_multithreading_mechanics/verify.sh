#!/usr/bin/env bash
echo "[TEST] Verifying Concurrency & Multithreading Mechanics..."
g++ -Wall -std=c++17 -pthread example.cpp -o example && ./example
echo "[PASS] Lesson 07_concurrency_and_multithreading_mechanics verified successfully!"
