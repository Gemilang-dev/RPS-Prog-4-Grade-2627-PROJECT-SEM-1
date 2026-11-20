# Lesson 09: Basic Preprocessor Directives

Welcome to Lesson 09! In this lesson, you will understand what preprocessor directives (`#include`, `#define`) do before the C++ compiler actually begins translating code.

---

## 🧒 Kid-Friendly Analogy: The Copy-Paste Assistant
Imagine you are typing a book on an old-fashioned typewriter with a robot assistant named **"Pre-Bob"**:
1. **The Magic Word Replacer (`#define`):**  
   At the top of the paper, you leave a sticky note for Pre-Bob:  
   `#define SCHOOL_BUS_CAPACITY 40`  
   Whenever Pre-Bob spots the exact word `SCHOOL_BUS_CAPACITY` anywhere in your manuscript, he takes an eraser and types the digits `40` in its place!
2. **The Sheet Stapler (`#include`):**  
   You write: `#include "bus_rules.txt"`  
   Pre-Bob walks to your filing cabinet, pulls out the `bus_rules.txt` sheet, photocopies all 50 lines from it, and staples it directly into your chapter!

Notice that Pre-Bob doesn't understand math, types, or C++ logic—he is strictly a **text substitution engine** that prepares the document before the real printer prints it!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Inspecting Preprocessor Output with `g++ -E`
You can see exactly what Pre-Bob does by asking `g++` to run **only** the preprocessor stage:
```bash
g++ -E example.cpp -o preprocessed.i
```
Open `preprocessed.i`—you will see that all `#include` headers were pasted directly into the file and all `#define` macros were replaced with their literal values!

### 2. `#include <...>` vs `#include "..."`
- `<header_name>` : Tells the preprocessor to search standard system directories (e.g., `<iostream>`, `<vector>`).
- `"header_name"` : Tells the preprocessor to search the **current local project directory first**, then fall back to system directories.

### 3. Why Modern C++ Prefers `constexpr` Over `#define`
Macros have no types and ignore scope rules:
```cpp
// ❌ Old C-Style Macro (No type checking, pollutes global scope)
#define MAX_BUFFER 1024

// ✅ Modern C++17 (Type-safe, scoped, debugger-friendly)
constexpr int MAX_BUFFER = 1024;
```

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>

// 1. Classic preprocessor macro replacement
#define MAX_SPEED_MPH 65
#define SQUARE(x) ((x) * (x))

// 2. Modern C++ type-safe constant alternative
constexpr int SAFE_PASSENGER_LIMIT = 50;

int main() {
    std::cout << "Demonstrating Preprocessor Macro Expansion...\n\n";

    std::cout << "  MAX_SPEED_MPH defined value: " << MAX_SPEED_MPH << " MPH\n";
    std::cout << "  Macro SQUARE(8): " << SQUARE(8) << "\n";
    std::cout << "  Modern constexpr Limit: " << SAFE_PASSENGER_LIMIT << " passengers\n\n";

    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/09_basic_preprocessor_directives/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/09_basic_preprocessor_directives
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In your terminal, run `g++ -E example.cpp | tail -n 25`. Notice how `MAX_SPEED_MPH` was replaced with the raw number `65` before the compiler ran!
