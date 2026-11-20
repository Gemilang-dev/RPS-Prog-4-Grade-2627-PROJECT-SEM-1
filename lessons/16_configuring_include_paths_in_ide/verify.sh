#!/usr/bin/env bash
echo "[TEST] Verifying Configuring Include Paths in IDE & Terminal..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 16_configuring_include_paths_in_ide verified successfully!"
