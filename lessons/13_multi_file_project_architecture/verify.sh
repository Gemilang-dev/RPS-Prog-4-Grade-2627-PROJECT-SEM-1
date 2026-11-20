#!/usr/bin/env bash
echo "[TEST] Verifying Multi-File Project Architecture..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 13_multi_file_project_architecture verified successfully!"
