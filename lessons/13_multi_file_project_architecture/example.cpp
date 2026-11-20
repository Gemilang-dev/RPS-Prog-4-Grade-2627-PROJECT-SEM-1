// Lesson 13: Multi-File Project Architecture - Educational Demonstration
#include <iostream>
#include <string>

// Simulating components that live across multiple files in a production system
struct CpuSubsystem {
    std::string name = "Virtual 4-Register Microprocessor";
    int clockSpeedHz = 1000;
};

struct QueueSubsystem {
    std::string name = "Passenger FIFO Ingestion Queue";
    int pendingCount = 14;
};

struct StackSubsystem {
    std::string name = "Transaction LIFO Rollback Stack";
    int historyDepth = 3;
};

class IntegratedSystemController {
private:
    CpuSubsystem cpu;
    QueueSubsystem queue;
    StackSubsystem stack;

public:
    void printArchitectureReport() {
        std::cout << "  [System Architecture Overview]\n";
        std::cout << "    1. include/cpu.h      -> " << cpu.name 
                  << " (Speed: " << cpu.clockSpeedHz << " ops/sec)\n";
        std::cout << "    2. include/queue.h    -> " << queue.name 
                  << " (" << queue.pendingCount << " passengers waiting)\n";
        std::cout << "    3. include/stack.h    -> " << stack.name 
                  << " (" << stack.historyDepth << " actions logged)\n";
    }
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 13: MULTI-FILE ARCHITECTURE DEMO\n";
    std::cout << "====================================================\n\n";

    IntegratedSystemController controller;
    controller.printArchitectureReport();

    std::cout << "\n[PASS] Multi-file architecture simulation successfully orchestrated!\n";
    return 0;
}
