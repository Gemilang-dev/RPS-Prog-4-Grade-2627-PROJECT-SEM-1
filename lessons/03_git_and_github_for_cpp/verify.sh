#!/usr/bin/env bash
echo "[TEST] Verifying Introduction to Git & GitHub for C++..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 03_git_and_github_for_cpp verified successfully!"
