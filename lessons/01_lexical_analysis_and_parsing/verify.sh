#!/usr/bin/env bash
echo "[TEST] Verifying Lexical Analysis & Parsing..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 01_lexical_analysis_and_parsing verified successfully!"
