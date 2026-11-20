#!/usr/bin/env bash
echo "[TEST] Verifying Thread Synchronization & Mutex Lock..."
g++ -Wall -std=c++17 -pthread example.cpp -o example && ./example
echo "[PASS] Lesson 08_thread_synchronization_and_mutex_lock verified successfully!"
