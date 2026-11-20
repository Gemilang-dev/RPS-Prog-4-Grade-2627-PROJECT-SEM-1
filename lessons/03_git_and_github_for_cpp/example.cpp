// Lesson 03: Git & GitHub for C++ Systems Programming - Educational Demonstration
#include <iostream>
#include <vector>
#include <string>

struct Commit {
    std::string hash;
    std::string message;
    std::string author;
    std::string timestamp;
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 03: GIT & GITHUB FOR C++ SYSTEMS DEMO\n";
    std::cout << "====================================================\n\n";

    std::vector<Commit> gitHistory = {
        {"7f8b91a", "feat: initialize modular project architecture and headers", "Alice", "10:00 AM"},
        {"c4d2e01", "feat(cpu): implement arithmetic register instructions", "Bob",   "10:45 AM"},
        {"a1b3c5d", "fix(queue): correct boundary check on empty dequeue",       "Alice", "11:30 AM"},
        {"9e8d7c6", "test: add automated unit tests for ALU verification",       "Bob",   "01:15 PM"}
    };

    std::cout << "--- Verified Commit Timeline (branch: main) ---\n";
    for (size_t i = 0; i < gitHistory.size(); ++i) {
        std::cout << "  [" << (i + 1) << "] Commit SHA: " << gitHistory[i].hash
                  << "\n      Message:    " << gitHistory[i].message
                  << "\n      Author:     " << gitHistory[i].author
                  << "\n      Time:       " << gitHistory[i].timestamp << "\n\n";
    }

    std::cout << "--- Git Best Practices Summary for Systems Students ---\n";
    std::cout << "  1. Never commit build artifacts (*.o, *.exe, binaries) -> use .gitignore!\n";
    std::cout << "  2. Write clear, imperative commit messages (e.g., 'feat: add MOV_AX instruction').\n";
    std::cout << "  3. Pull changes before creating a new feature branch.\n\n";

    std::cout << "[PASS] Git systems collaboration demonstration completed successfully!\n";
    return 0;
}
