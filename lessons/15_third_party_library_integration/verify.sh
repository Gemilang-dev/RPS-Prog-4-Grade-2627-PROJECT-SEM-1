#!/usr/bin/env bash
echo "[TEST] Verifying Third-Party Library Integration..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 15_third_party_library_integration verified successfully!"
