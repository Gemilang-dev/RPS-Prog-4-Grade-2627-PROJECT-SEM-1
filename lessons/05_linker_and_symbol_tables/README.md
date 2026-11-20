# Lesson 05: The Linker & Symbol Tables

Welcome to Lesson 05! In this lesson, you will demystify the Linker—the tool that connects multiple compiled object files into a single runnable executable.

---

## 🧒 Kid-Friendly Analogy: The Scavenger Hunt & The Referee
Imagine you and your school team are participating in a treasure hunt:
- You receive **Clue Card A**: *"To open the treasure box, ask Teammate B for the secret 4-digit code!"*
- Your teammate holds **Clue Card B**: *"The secret code is 7492."*

Each clue card is like a compiled `.o` file.  
The **Linker** is the referee who takes Card A and Card B and connects them together so the treasure box can be opened!

### What happens when things go wrong?
1. **The Missing Clue (`undefined reference`):**  
   If Teammate B lost Card B, you are stuck holding Card A with no answer! The referee stops the game:  
   ❌ `undefined reference to 'getSecretCode()'`
2. **The Double Clue (`multiple definition`):**  
   If two different teammates both hand you Card B with different codes, the referee gets confused:  
   ❌ `multiple definition of 'secretCode'`

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. The Role of the Linker
Compiling a multi-file C++ program happens in two phases:
```
  [turnstile_cpu.cpp]  ──(compile: g++ -c)──>  [turnstile_cpu.o] 
                                                        │
  [passenger_queue.cpp]──(compile: g++ -c)──>  [passenger_queue.o]──(LINKER)──> [transit_gate (binary)]
                                                        │
  [main.cpp]           ──(compile: g++ -c)──>  [main.o]
```
The compiler processes each `.cpp` file independently in isolation. It doesn't know where other functions live yet! It trusts that the Linker will connect the puzzle pieces later.

### 2. Symbol Tables (`nm` command)
Every object file contains a dictionary of names called a **Symbol Table**:
- **Defined Symbols (`T` - Text/Code):** Functions implemented in this object file.
- **Undefined Symbols (`U` - Undefined):** Functions called in this file whose implementation lives somewhere else.

You can inspect symbols in any `.o` file using the terminal tool `nm`:
```bash
nm -C turnstile_cpu.o
```

### 3. Diagnosing Common Linker Errors
- **`undefined reference to ...`**: You forgot to pass the `.cpp` or `.o` file to the compiler command (e.g., ran `g++ main.cpp -o app` without `turnstile_cpu.cpp`).
- **`multiple definition of ...`**: A function or variable was defined multiple times across translation units (often caused by placing function bodies inside `.h` files without the `inline` keyword).

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <vector>
#include <string>

struct Symbol {
    std::string name;
    char type; // 'T' = defined in text/code section, 'U' = undefined external
    std::string sourceFile;
};

int main() {
    std::cout << "Simulating Linker Symbol Table Resolution...\n\n";

    std::vector<Symbol> symbolTables = {
        {"TurnstileCPU::MOV_AX(int)", 'T', "turnstile_cpu.o"},
        {"PassengerQueue::enqueue(Passenger)", 'T', "passenger_queue.o"},
        {"main", 'T', "main.o"},
        {"TurnstileCPU::MOV_AX(int)", 'U', "main.o"}, // main calls this
        {"PassengerQueue::enqueue(Passenger)", 'U', "main.o"} // main calls this
    };

    std::cout << "--- Symbol Table Registry ---\n";
    for (const auto& s : symbolTables) {
        std::cout << "  [" << s.type << "] " << s.name << "  (from " << s.sourceFile << ")\n";
    }

    std::cout << "\nLinker Action: Matching all [U] external symbols with corresponding [T] definitions...\n";
    std::cout << "All symbols resolved. Emitting final executable ELF binary!\n\n";

    std::cout << "[PASS] Linker resolution demonstration complete.\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/05_linker_and_symbol_tables/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/05_linker_and_symbol_tables
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In your terminal, compile `example.cpp` into an object file using `g++ -c example.cpp -o example.o`, then run `nm -C example.o`. Find the `main` function in the symbol list!
