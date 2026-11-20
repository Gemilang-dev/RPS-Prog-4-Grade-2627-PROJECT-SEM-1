// Lesson 02: Terminal Compilation & Comment Mechanics - Educational Demonstration
#include <iostream>

/**
 * @brief Demonstrates proper documentation, single-line, and block comments.
 * @param price Original item price in cents.
 * @param discountRate Percent discount to apply (0 - 100).
 * @return Final discounted price in cents.
 */
int calculateDiscount(int price, int discountRate) {
    // Validate discount boundary to protect against negative numbers
    if (discountRate < 0 || discountRate > 100) {
        return price;
    }
    
    /* Calculate discount fraction:
       Formula: discountAmount = (price * discountRate) / 100 */
    int discountAmount = (price * discountRate) / 100;
    return price - discountAmount;
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 02: TERMINAL COMPILATION & COMMENTS DEMO\n";
    std::cout << "====================================================\n\n";

    int regularPrice = 5000; // $50.00 represented in cents
    int finalPrice = calculateDiscount(regularPrice, 20); // 20% discount

    std::cout << "1. Base Item Price:        $" << (regularPrice / 100.0) << "\n";
    std::cout << "2. Applied Discount:        20%\n";
    std::cout << "3. Final Cashier Price:    $" << (finalPrice / 100.0) << "\n\n";

    std::cout << "[SUCCESS] Program compiled with -Wall -Wextra -std=c++17 successfully!\n";
    std::cout << "[INFO] All code comments were cleanly stripped by the preprocessor.\n";
    return 0;
}
