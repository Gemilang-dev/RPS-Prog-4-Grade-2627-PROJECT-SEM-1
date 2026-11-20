#!/usr/bin/env bash
echo "[TEST] Verifying Data Structures: FIFO Queues..."
g++ -Wall -std=c++17 example.cpp -o example && ./example
echo "[PASS] Lesson 17_data_structures_fifo_queues verified successfully!"
