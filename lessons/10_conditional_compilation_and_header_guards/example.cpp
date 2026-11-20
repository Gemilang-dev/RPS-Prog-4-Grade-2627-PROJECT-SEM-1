// Lesson 10: Conditional Compilation & Header Guards - Educational Demonstration
#include <iostream>

// 1. Simulating an active build flag (-DDEBUG_MODE)
#define DEBUG_MODE

void logCommuterScan(int commuterId, int balanceCents) {
#ifdef DEBUG_MODE
    std::cout << "  [DEBUG LOG] Sensor RF-ID triggered for Commuter #" << commuterId 
              << " | Raw Balance: " << balanceCents << " cents.\n";
#endif
    std::cout << "  Turnstile Gate: Granted entry to commuter #" << commuterId << "\n";
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 10: CONDITIONAL COMPILATION & GUARDS DEMO\n";
    std::cout << "====================================================\n\n";

    std::cout << "--- 1. Testing Conditional Debug Compilation ---\n";
    logCommuterScan(101, 500);
    logCommuterScan(102, 250);

    std::cout << "\n--- 2. Build Configuration Status ---\n";
#ifdef DEBUG_MODE
    std::cout << "  Current Active Profile: [DEBUG BUILD] (Verbose telemetry enabled)\n";
#else
    std::cout << "  Current Active Profile: [RELEASE BUILD] (Zero logging overhead)\n";
#endif

    std::cout << "\n[PASS] Conditional compilation & header guards demonstration completed successfully!\n";
    return 0;
}
