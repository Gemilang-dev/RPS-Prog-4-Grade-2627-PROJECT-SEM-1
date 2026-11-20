#!/usr/bin/env bash
echo "[TEST] Verifying Resolving Namespace Conflicts..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 12_resolving_namespace_conflicts verified successfully!"
