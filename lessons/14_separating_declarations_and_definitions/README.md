# Lesson 14: Separating Declarations (.h) & Definitions (.cpp)

Welcome to Lesson 14! This is one of the **most essential lessons** for completing your Team Projects (`project1_transit_gate`, `project2_warehouse_robot`, and `project3_hospital_triage`).

---

## 🧒 Kid-Friendly Analogy: The Restaurant Menu vs The Kitchen Chef Cooking
Imagine you sit down at your favorite pizza and burger diner:
1. **The Printed Menu (`.h` Header File):**  
   The waiter hands you a clean, laminated menu. It says:  
   `Burger orderBurger(int cheeseSlices, bool extraPickles);`  
   The menu tells you what you can order, what ingredients go in, and what comes out.  
   Notice what the menu **does NOT** contain: It does not have the giant flaming grill, the greasy spatulas, or the chef sweating over the stove! The menu is purely a **Declaration** (a promise of what can be made).
2. **The Kitchen (`.cpp` Source File):**  
   Behind the double doors in the kitchen, the chef turns on the flame, grills the patty, melts the cheddar, and plates the burger. That is the **Definition** (the real work!).

### Why do we separate them?
- Any file in your project can read the Menu (`#include "menu.h"`) to place an order without needing to know how the kitchen works.
- If the chef upgrades to a faster grill inside the kitchen (`menu.cpp`), customers' menus don't have to be reprinted!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Declarations vs Definitions
- **Declaration (`.h`):** Introduces a name and its type signature to the compiler so code can be syntax-checked. Allocates **zero bytes of machine code**.
  ```cpp
  // turnstile_cpu.h
  #pragma once
  struct TurnstileCPU {
      int AX;
      void MOV_AX(int balance); // Declaration only! Semicolon at end.
  };
  ```
- **Definition (`.cpp`):** Supplies the actual function body with executable instructions.
  ```cpp
  // turnstile_cpu.cpp
  #include "turnstile_cpu.h"

  // Notice the ClassName:: prefix!
  void TurnstileCPU::MOV_AX(int balance) {
      AX = balance; // Definition body!
  }
  ```

### 2. The Scope Resolution Operator (`TurnstileCPU::`)
When implementing a function in `.cpp`, you **must** prefix the function name with `ClassName::`.  
Without `TurnstileCPU::`, the compiler thinks you are defining a brand new standalone global function named `MOV_AX`, and will give you a linker error:  
❌ `undefined reference to TurnstileCPU::MOV_AX(int)`!

### 3. The One Definition Rule (ODR)
If you place a function body `{ ... }` directly inside a header file without the `inline` keyword, and two different `.cpp` files include that header, the compiler emits two identical copies of machine code into both `.o` files. When linking, the linker crashes:  
❌ `multiple definition of 'FunctionName()'`!

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>

// ==========================================
// 1. DECLARATIONS (Normally in Calculator.h)
// ==========================================
class Calculator {
public:
    int add(int a, int b);
    int multiply(int a, int b);
};

// ==========================================
// 2. DEFINITIONS (Normally in Calculator.cpp)
// ==========================================
int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}

// ==========================================
// 3. CONSUMER CODE (Normally in main.cpp)
// ==========================================
int main() {
    std::cout << "Testing Separated Declarations and Definitions...\n\n";

    Calculator calc;
    std::cout << "  5 + 7 = " << calc.add(5, 7) << "\n";
    std::cout << "  6 * 8 = " << calc.multiply(6, 8) << "\n\n";

    std::cout << "[PASS] Declarations and definitions separated cleanly!\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/14_separating_declarations_and_definitions/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/14_separating_declarations_and_definitions
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Direct Connection to Your Team Projects!
In **Project 1** (`turnstile_cpu.cpp`), **Project 2** (`robot_alu.cpp`), and **Project 3** (`vitals_cpu.cpp`), your exact job is writing the **Definitions** in `.cpp` for the **Declarations** already written in the `.h` header files!
