// ========================================================
// Demonstration: Anatomy of Comments in C++
// Compile & Run:
//   g++ comment_demo.cpp -Wall -o comment_demo && ./comment_demo
// ========================================================

#include <iostream>
#include <string>

// 1. SINGLE-LINE COMMENT
// The '//' syntax ignores all characters to its right until the newline.

/* 
 * 2. MULTI-LINE / BLOCK COMMENT
 * Begins with '/*' and closes with '* /'
 * The asterisks at the start of each line are optional styling convention.
 */

/**
 * 3. DOCUMENTATION COMMENT (DOXYGEN STYLE)
 * Uses '/**' and structured tags (@param, @return)
 * Parsed by automated documentation tools like Doxygen.
 * 
 * @param studentName Name of the learner to greet.
 */
void greetStudent(const std::string& studentName) {
    std::cout << "Happy coding in C++, " << studentName << "!" << std::endl;
}

int main() {
    // Invoke the documented function
    greetStudent("Systems Architect");

    /*
     * COMPILATION NOTE:
     * Before compilation to assembly or binary, the preprocessor
     * strips every single comment and replaces it with a single space.
     * The final binary output contains zero comment text!
     */

    std::cout << "Demonstration executed successfully." << std::endl;
    return 0;
}
