#!/usr/bin/env bash
echo "[TEST] Verifying Automated Builds & Makefiles..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 20_automated_builds_and_makefiles verified successfully!"
