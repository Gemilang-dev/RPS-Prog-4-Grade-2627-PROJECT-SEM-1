// Lesson 04: Compiler Optimization & Object Files - Educational Demonstration
#include <iostream>
#include <chrono>

// Small inline function suitable for compiler inlining optimization
inline long long computeCube(int n) {
    return static_cast<long long>(n) * n * n;
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 04: COMPILER OPTIMIZATIONS & OBJECT FILES\n";
    std::cout << "====================================================\n\n";

    // 1. Constant folding demonstration
    // The expression below is fully computed at compile-time by the compiler
    const int secondsInDay = 60 * 60 * 24;
    std::cout << "[Constant Folding] Seconds in one full day: " << secondsInDay << "\n";
    std::cout << "  -> Evaluated to literal 86400 during compilation (zero CPU cycles at runtime)!\n\n";

    // 2. Performance benchmark
    std::cout << "--- Benchmarking Loop Throughput ---\n";
    const int ITERATIONS = 5000000;
    auto start = std::chrono::high_resolution_clock::now();

    long long accumulator = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        accumulator += (i % 7);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "  Processed " << ITERATIONS << " loop steps.\n";
    std::cout << "  Accumulator Result: " << accumulator << "\n";
    std::cout << "  Elapsed Time:       " << duration.count() << " milliseconds.\n\n";

    std::cout << "[PASS] Object file & compiler optimization demonstration completed successfully!\n";
    return 0;
}
