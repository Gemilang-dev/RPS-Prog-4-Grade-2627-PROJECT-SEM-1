# Lesson 06: OS Execution Model: Stack vs Heap Memory

Welcome to Lesson 06! In this lesson, you will explore how the Operating System allocates memory to a running C++ program, comparing fast automatic Stack memory with dynamic Heap storage.

---

## 🧒 Kid-Friendly Analogy: The School Backpack vs The Giant Storage Warehouse

### 🎒 The Stack: Your Everyday School Backpack
- **Fast & Automatic:** You keep your current pencils and class notebook right in your backpack. When Math class starts, you take out your notebook (pushing onto the stack). When class ends, you put it away (popping off the stack).
- **Strict Size Limit:** Your backpack is small. If you try to stuff 1,000 thick encyclopedia volumes into it at once, the zipper tears open! In computer programming, that is called a **Stack Overflow**!

### 🏭 The Heap: The Giant Rented Storage Warehouse
- **Massive & Flexible:** The warehouse has unlimited space for huge items (giant arrays, 3D video game worlds, millions of customer records).
- **Manual Check-In & Check-Out:** You have to ask the warehouse manager for a storage unit (`new` or `std::make_unique`). When you finish using it, you **must** tell the manager you are done (`delete` or smart pointer destruction). If you forget, your storage bill piles up and you run out of memory—a **Memory Leak**!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Process Memory Layout in RAM
When the OS launches your C++ program, it creates a virtual address space:
```
  High Memory Address (0x7FFF...)
  ┌─────────────────────────────────┐
  │         STACK (Grows DOWN)      │  <-- Local variables, function return addresses
  │                 │               │
  │                 ▼               │
  │                                 │
  │                 ▲               │
  │                 │               │
  │         HEAP (Grows UP)         │  <-- Dynamic allocations (new, malloc, std::vector)
  ├─────────────────────────────────┤
  │         BSS & Global Data       │  <-- Global & static variables
  ├─────────────────────────────────┤
  │         Text / Code Segment     │  <-- Read-only compiled CPU machine instructions
  └─────────────────────────────────┘
  Low Memory Address (0x0000...)
```

### 2. Stack vs Heap Comparison Matrix
| Feature | Stack Memory | Heap Memory |
| :--- | :--- | :--- |
| **Allocation Speed** | Instantaneous (1 CPU instruction pointer bump) | Slower (requires searching free list in OS memory manager) |
| **Lifetime** | Automatic (freed when function exits scope) | Manual / RAII (persists until explicitly deleted) |
| **Risk** | Stack Overflow (deep recursion or huge arrays) | Memory Leaks & Memory Fragmentation |
| **C++ Modern Syntax** | `int val = 42;` | `auto ptr = std::make_unique<int>(42);` |

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <memory>

void demonstrateStack(int depth) {
    int localVar = depth * 10;
    std::cout << "  Stack Frame [depth " << depth << "] variable address: " << &localVar << "\n";
    if (depth < 3) {
        demonstrateStack(depth + 1); // Notice stack addresses decrease as stack grows down!
    }
}

int main() {
    std::cout << "--- 1. Inspecting Stack Addresses (Grows Downward) ---\n";
    demonstrateStack(1);

    std::cout << "\n--- 2. Inspecting Heap Allocation (Modern RAII Smart Pointer) ---\n";
    // Modern C++ heap allocation using std::unique_ptr (automatically freed when out of scope!)
    auto heapArray = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        heapArray[i] = (i + 1) * 100;
    }
    std::cout << "  Heap memory address: " << heapArray.get() << "\n";
    std::cout << "  First element value: " << heapArray[0] << "\n";
    std::cout << "  [RAII Guarantee] Heap memory will be automatically freed safely without leaks!\n";

    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/06_os_execution_model_stack_vs_heap/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/06_os_execution_model_stack_vs_heap
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In `example.cpp`, notice how the printed memory addresses of `localVar` get smaller with each recursion. That visually proves that the stack grows **downward** toward lower memory addresses on x86/ARM systems!
