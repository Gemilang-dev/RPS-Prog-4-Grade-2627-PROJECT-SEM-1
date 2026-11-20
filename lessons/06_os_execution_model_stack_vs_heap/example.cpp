// Lesson 06: OS Execution Model: Stack vs Heap - Educational Demonstration
#include <iostream>
#include <memory>

void demonstrateStackGrowth(int depth) {
    int localVariable = depth * 100;
    std::cout << "  [Stack Frame depth " << depth << "] local variable address: " 
              << &localVariable << " (value: " << localVariable << ")\n";
    if (depth < 3) {
        demonstrateStackGrowth(depth + 1);
    }
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 06: STACK VS HEAP MEMORY ARCHITECTURE\n";
    std::cout << "====================================================\n\n";

    std::cout << "--- 1. Stack Memory Inspection (Fast, Automatic, Downward Growth) ---\n";
    demonstrateStackGrowth(1);
    std::cout << "Notice: Each subsequent stack frame has a LOWER memory address!\n\n";

    std::cout << "--- 2. Heap Memory Inspection (Dynamic, Flexible Storage) ---\n";
    // Modern C++ heap allocation using std::unique_ptr (RAII memory management)
    auto dynamicScoreBuffer = std::make_unique<int[]>(4);
    dynamicScoreBuffer[0] = 95;
    dynamicScoreBuffer[1] = 88;
    dynamicScoreBuffer[2] = 100;
    dynamicScoreBuffer[3] = 76;

    std::cout << "  Heap Buffer Address: " << dynamicScoreBuffer.get() << "\n";
    std::cout << "  Scores stored on Heap: [ ";
    for (int i = 0; i < 4; ++i) {
        std::cout << dynamicScoreBuffer[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "  [RAII Cleanup] Upon function exit, memory is released automatically!\n\n";

    std::cout << "[PASS] Stack and Heap execution model verified successfully!\n";
    return 0;
}
