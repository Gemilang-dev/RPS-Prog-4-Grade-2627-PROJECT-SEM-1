// Lesson 07: Concurrency & Multithreading Mechanics - Educational Demonstration
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void prepareIngredient(std::string taskName, int durationMs) {
    std::cout << "  [Chef Thread Started] " << taskName << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(durationMs));
    std::cout << "  [Chef Thread Finished] " << taskName << " ready!\n";
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 07: CONCURRENCY & MULTITHREADING DEMO\n";
    std::cout << "====================================================\n\n";

    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "Detected CPU Hardware Concurrency: " << cores << " core threads.\n\n";

    std::cout << "--- Spawning 3 Kitchen Chefs in Parallel ---\n";
    auto start = std::chrono::high_resolution_clock::now();

    std::thread chef1(prepareIngredient, "Rolling Pizza Dough", 120);
    std::thread chef2(prepareIngredient, "Grating Fresh Mozzarella", 80);
    std::thread chef3(prepareIngredient, "Slicing Pepperoni & Basil", 100);

    // Wait for all 3 threads to complete
    chef1.join();
    chef2.join();
    chef3.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> totalTime = end - start;

    std::cout << "\nAll ingredients ready! Total parallel kitchen time: " 
              << totalTime.count() << " ms\n";
    std::cout << "(Note: Notice the total time is around the longest task (~120ms), NOT 120+80+100 = 300ms!)\n\n";

    std::cout << "[PASS] Multithreading demonstration completed successfully!\n";
    return 0;
}
