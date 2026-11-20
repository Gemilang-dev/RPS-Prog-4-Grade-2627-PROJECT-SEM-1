// Lesson 20: Automated Builds & Makefiles - Educational Demonstration
#include <iostream>
#include <vector>
#include <string>

struct BuildTarget {
    std::string targetFile;
    std::vector<std::string> prerequisites;
    bool modifiedSinceLastBuild;
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 20: AUTOMATED BUILDS & MAKEFILES DEMO\n";
    std::cout << "====================================================\n\n";

    std::vector<BuildTarget> makeGraph = {
        {"src/turnstile_cpu.o", {"src/turnstile_cpu.cpp", "include/turnstile_cpu.h"}, true},
        {"src/passenger_queue.o", {"src/passenger_queue.cpp", "include/passenger_queue.h"}, false},
        {"src/refund_stack.o", {"src/refund_stack.cpp", "include/refund_stack.h"}, false},
        {"src/main.o", {"src/main.cpp", "include/turnstile_controller.h"}, false},
        {"transit_gate", {"src/turnstile_cpu.o", "src/passenger_queue.o", "src/refund_stack.o", "src/main.o"}, true}
    };

    std::cout << "--- Evaluating Makefile Dependency Graph (Simulated `make all`) ---\n";
    int compileSteps = 0;
    for (const auto& node : makeGraph) {
        if (node.modifiedSinceLastBuild) {
            std::cout << "  -> [COMPILE/LINK] Target: " << node.targetFile << " (Prerequisites modified!)\n";
            compileSteps++;
        } else {
            std::cout << "  -> [CACHE HIT]   Target: " << node.targetFile << " (Up-to-date. Skipped)\n";
        }
    }

    std::cout << "\nBuild Summary: Only " << compileSteps << " of " << makeGraph.size() 
              << " targets required rebuild.\n";
    std::cout << "Incremental build saved massive CPU time and disk I/O!\n\n";

    std::cout << "[PASS] Automated build dependency evaluation completed successfully!\n";
    return 0;
}
