// ========================================================
// Terminal Training: Hello World in Modern C++
// Compile:
//   g++ hello.cpp -Wall -std=c++17 -o hello
// Run:
//   ./hello
// ========================================================

#include <iostream>
#include <string>

int main() {
    std::string learnerName = "Future Systems Engineer";
    
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Welcome to Systems Programming, " << learnerName << "!" << std::endl;
    
    return 0;
}
