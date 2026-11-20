// Lesson 14: Separating Declarations (.h) & Definitions (.cpp) - Educational Demonstration
#include <iostream>

// ==============================================================================
// 1. DECLARATION INTERFACE (What exists - normally in `VirtualAlu.h`)
// ==============================================================================
class VirtualAlu {
public:
    int accumulator = 0;

    void load(int value);
    void add(int value);
    void multiply(int factor);
    bool isGreaterThanZero() const;
};

// ==============================================================================
// 2. DEFINITION IMPLEMENTATION (How it works - normally in `VirtualAlu.cpp`)
// ==============================================================================
// Notice the `VirtualAlu::` class prefix for every member function!
void VirtualAlu::load(int value) {
    accumulator = value;
}

void VirtualAlu::add(int value) {
    accumulator += value;
}

void VirtualAlu::multiply(int factor) {
    accumulator *= factor;
}

bool VirtualAlu::isGreaterThanZero() const {
    return accumulator > 0;
}

// ==============================================================================
// 3. MAIN RUNNER (Driver code - normally in `main.cpp`)
// ==============================================================================
int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 14: SEPARATING DECLARATIONS & DEFINITIONS\n";
    std::cout << "====================================================\n\n";

    VirtualAlu alu;
    std::cout << "1. Executing alu.load(25)...\n";
    alu.load(25);
    std::cout << "   Current Accumulator: " << alu.accumulator << "\n";

    std::cout << "2. Executing alu.add(15)...\n";
    alu.add(15);
    std::cout << "   Current Accumulator: " << alu.accumulator << "\n";

    std::cout << "3. Executing alu.multiply(2)...\n";
    alu.multiply(2);
    std::cout << "   Current Accumulator: " << alu.accumulator << "\n";

    std::cout << "4. Evaluating alu.isGreaterThanZero(): " 
              << (alu.isGreaterThanZero() ? "TRUE" : "FALSE") << "\n\n";

    std::cout << "[PASS] Declarations and definitions separated cleanly!\n";
    std::cout << "[NOTE] Use this exact ClassName::MethodName pattern in your team project!\n";
    return 0;
}
