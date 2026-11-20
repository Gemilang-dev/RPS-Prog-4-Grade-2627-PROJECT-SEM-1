// Lesson 09: Basic Preprocessor Directives - Educational Demonstration
#include <iostream>

// 1. Classic Preprocessor text substitution macro
#define MAX_SPEED_LIMIT 75
#define MULTIPLY(a, b) ((a) * (b))

// 2. Modern C++ type-safe, scoped alternative
constexpr int FACTORY_MAX_TEMPERATURE_CELSIUS = 120;

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 09: PREPROCESSOR DIRECTIVES DEMONSTRATION\n";
    std::cout << "====================================================\n\n";

    std::cout << "--- 1. Literal Text Substitution (#define) ---\n";
    std::cout << "  Defined Speed Limit: " << MAX_SPEED_LIMIT << " MPH\n";
    std::cout << "  Evaluated MULTIPLY(6, 7): " << MULTIPLY(6, 7) << "\n\n";

    std::cout << "--- 2. Modern C++ Type-Safe Alternative (constexpr) ---\n";
    std::cout << "  Factory Temperature Limit: " << FACTORY_MAX_TEMPERATURE_CELSIUS << " °C\n";
    std::cout << "  (Benefits: checked by compiler types, visible in GDB debugger, respects scope!)\n\n";

    std::cout << "[PASS] Preprocessor directives demonstration completed successfully!\n";
    return 0;
}
