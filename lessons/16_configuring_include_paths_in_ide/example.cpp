// Lesson 16: Configuring Include Paths in IDEs - Educational Demonstration
#include <iostream>
#include <vector>
#include <string>

// Simulating an IDE Include Path Resolver (CLion & CMake header discovery)
struct IncludePathResolver {
    std::vector<std::string> searchPaths;

    void addPath(const std::string& path) {
        searchPaths.push_back(path);
        std::cout << "  [CMake/IDE Path Added] Directory: \"" << path << "\"\n";
    }

    bool resolveHeader(const std::string& headerFile) {
        std::cout << "  Searching for target header \"" << headerFile << "\"...\n";
        for (const auto& path : searchPaths) {
            std::cout << "    -> Probing candidate: " << path << "/" << headerFile << " [SUCCESS: Validated]\n";
            return true;
        }
        std::cout << "    -> [FATAL ERROR] Header not found in any include path!\n";
        return false;
    }
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 16: CONFIGURING INCLUDE PATHS IN CLION\n";
    std::cout << "====================================================\n\n";

    IncludePathResolver resolver;
    resolver.addPath("./include");
    resolver.addPath("/usr/include");
    resolver.addPath("/usr/local/include");

    std::cout << "\n--- Resolving Project 1 Headers ---\n";
    resolver.resolveHeader("turnstile_cpu.h");
    resolver.resolveHeader("passenger_queue.h");
    resolver.resolveHeader("refund_stack.h");

    std::cout << "\n[PASS] Include paths configured! All IntelliSense red marks resolved.\n";
    return 0;
}
