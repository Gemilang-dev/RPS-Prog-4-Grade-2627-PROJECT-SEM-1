# Lesson 02: Terminal Compilation & Comment Mechanics

Welcome to Lesson 02! In this lesson, you will master compiling modern C++ programs directly from the terminal using `g++`, understanding compiler warnings, and learning how comments are processed.

---

## 🧒 Kid-Friendly Analogy: Sticky Notes on Grandma's Recipe
Imagine you are baking chocolate chip cookies from grandma's recipe book:
- On the page, you stick a yellow sticky note: `// Note: Wash hands first!`
- In the corner, you add another note: `/* Remember: oven tray gets super hot! */`

These notes are written for **you** (the human).  
When you feed the recipe into a smart robotic kitchen baker (the C++ compiler), the very first robot helper (**The Preprocessor**) removes all your sticky notes before baking. The final batch of cookies (the executable file) contains chocolate, sugar, and flour, but **zero sticky notes**!

That's why adding hundreds of comments to your code never makes your executable program slower or larger—the compiler strips every single comment before creating machine code!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. The 4 Stages of the Compilation Pipeline
When you compile `example.cpp`, `g++` performs 4 sequential transformations:
```
  [example.cpp] 
        │  Stage 1: Preprocessor (strips comments, expands #include & #define)
        ▼
  [preprocessed.i] 
        │  Stage 2: Compiler (translates C++ syntax into assembly instructions)
        ▼
  [assembly.s] 
        │  Stage 3: Assembler (translates assembly into binary machine code)
        ▼
  [object.o] 
        │  Stage 4: Linker (combines object files with C++ standard library)
        ▼
  [executable application (ELF / Mach-O / PE)]
```

### 2. Comment Anatomy in C++
- **Single-Line Comment (`//`)**: Everything from `//` until the end of the line is ignored.
- **Multi-Line Block Comment (`/* ... */`)**: Ignores everything between `/*` and `*/`.
- ⚠️ **Why Block Comments Cannot Be Nested**:
  ```cpp
  /* Outer comment
      /* Inner comment */  <-- This closing marker terminates the ENTIRE block!
     Code here causes a SYNTAX ERROR! */
  ```
  The compiler searches for the *very first* `*/` and ends the comment right there, leaving the rest as broken syntax.

### 3. Essential Compiler Flags
- `-Wall` : Activates **all** standard compiler warning messages.
- `-Wextra` : Activates extra warning checks for even safer code.
- `-std=c++17` : Enforces modern C++17 language standards.
- `-o <name>` : Specifies the name of the output binary executable.
- `&&` : Command chaining; executes the next command **only if** the previous one succeeded:
  ```bash
  g++ -Wall -Wextra -std=c++17 example.cpp -o example && ./example
  ```

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
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
    std::cout << "Testing compiler comment stripping & execution pipeline...\n";
    int regularPrice = 5000; // $50.00 represented in cents
    int finalPrice = calculateDiscount(regularPrice, 20); // 20% discount
    std::cout << "Original: $" << (regularPrice / 100.0) 
              << " | After Discount: $" << (finalPrice / 100.0) << "\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/02_terminal_compilation_and_comments/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/02_terminal_compilation_and_comments
g++ -Wall -Wextra -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
Try deliberately nesting a block comment `/* /* inner */ outer */` inside `example.cpp` and re-compile in your terminal. Observe the exact error message `g++` gives you! Then remove it so the build succeeds.
