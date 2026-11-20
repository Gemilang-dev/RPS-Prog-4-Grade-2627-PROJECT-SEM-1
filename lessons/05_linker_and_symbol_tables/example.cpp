// Lesson 05: The Linker & Symbol Tables - Educational Demonstration
#include <iostream>
#include <vector>
#include <string>

struct Symbol {
    std::string name;
    char type; // 'T' = defined text/code, 'U' = undefined external reference
    std::string translationUnit;
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 05: THE LINKER & SYMBOL TABLES DEMO\n";
    std::cout << "====================================================\n\n";

    std::vector<Symbol> symbolRegistry = {
        {"TurnstileCPU::MOV_AX(int)",           'T', "turnstile_cpu.o"},
        {"TurnstileCPU::COMPUTE_FARE()",        'T', "turnstile_cpu.o"},
        {"PassengerQueue::enqueue(Passenger)", 'T', "passenger_queue.o"},
        {"main",                                'T', "main.o"},
        {"TurnstileCPU::MOV_AX(int)",           'U', "main.o"},
        {"TurnstileCPU::COMPUTE_FARE()",        'U', "main.o"},
        {"PassengerQueue::enqueue(Passenger)", 'U', "main.o"}
    };

    std::cout << "--- Inspecting Object File Symbol Tables (Simulated `nm -C`) ---\n";
    for (const auto& sym : symbolRegistry) {
        std::cout << "  [" << sym.type << "] " << sym.name 
                  << "  \t(File: " << sym.translationUnit << ")\n";
    }

    std::cout << "\n--- Linker Resolution Phase ---\n";
    std::cout << "  1. Scans main.o -> Found undefined symbol 'TurnstileCPU::MOV_AX(int)'.\n";
    std::cout << "  2. Resolves symbol address to turnstile_cpu.o [T: 0x00401120].\n";
    std::cout << "  3. Scans main.o -> Found undefined symbol 'PassengerQueue::enqueue(...)'.\n";
    std::cout << "  4. Resolves symbol address to passenger_queue.o [T: 0x00401240].\n";
    std::cout << "  5. All external addresses linked. Generating final executable binary!\n\n";

    std::cout << "[PASS] Linker resolution demonstration completed successfully!\n";
    return 0;
}
