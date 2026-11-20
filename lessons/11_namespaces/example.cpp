// Lesson 11: Namespaces in C++ - Educational Demonstration
#include <iostream>
#include <string>

namespace Transit {
    class GateController {
    public:
        void openGate() {
            std::cout << "  [Transit::GateController] Turnstile barrier unlocked for commuter.\n";
        }
    };
    const int DEFAULT_TIMEOUT_SECONDS = 15;
}

namespace Warehouse {
    class GateController {
    public:
        void openGate() {
            std::cout << "  [Warehouse::GateController] Heavy cargo bay blast door opening.\n";
        }
    };
    const int DEFAULT_TIMEOUT_SECONDS = 60;
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 11: C++ NAMESPACES DEMONSTRATION\n";
    std::cout << "====================================================\n\n";

    std::cout << "--- 1. Calling Identically Named Classes in Separate Namespaces ---\n";
    Transit::GateController transitGate;
    Warehouse::GateController warehouseGate;

    transitGate.openGate();
    warehouseGate.openGate();

    std::cout << "\n--- 2. Inspecting Scoped Constants ---\n";
    std::cout << "  Transit Timeout:   " << Transit::DEFAULT_TIMEOUT_SECONDS << " seconds\n";
    std::cout << "  Warehouse Timeout: " << Warehouse::DEFAULT_TIMEOUT_SECONDS << " seconds\n\n";

    std::cout << "[PASS] Namespaces successfully isolated both subsystems!\n";
    return 0;
}
