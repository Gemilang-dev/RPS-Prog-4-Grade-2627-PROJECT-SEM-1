// ========================================================
// Terminal Training Exercise: Interactive Calculator
// Compile with C++17 and Warning Flags:
//   g++ calculator.cpp -Wall -Wextra -std=c++17 -o calculator
// Run:
//   ./calculator
// ========================================================

#include <iostream>

/**
 * @brief Computes a basic arithmetic operation.
 * @param a First operand.
 * @param b Second operand.
 * @param op Operator character (+, -, *, /).
 * @return The calculated numerical result.
 */
double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0.0) {
                std::cout << "[Warning] Division by zero is undefined!" << std::endl;
                return 0.0;
            }
            return a / b;
        default:
            std::cout << "[Warning] Unrecognized operator: " << op << std::endl;
            return 0.0;
    }
}

int main() {
    double x = 0.0;
    double y = 0.0;
    char op = '+';

    std::cout << "=== TERMINAL C++ CALCULATOR ===" << std::endl;
    std::cout << "Enter first number: ";
    if (!(std::cin >> x)) return 1;

    std::cout << "Enter operator (+, -, *, /): ";
    if (!(std::cin >> op)) return 1;

    std::cout << "Enter second number: ";
    if (!(std::cin >> y)) return 1;

    double result = calculate(x, y, op);
    std::cout << "Result: " << x << " " << op << " " << y << " = " << result << std::endl;

    return 0;
}
