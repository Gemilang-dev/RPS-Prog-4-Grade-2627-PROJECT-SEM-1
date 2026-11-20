# Lesson 13: Multi-File Project Architecture

Welcome to Lesson 13! In this lesson, you will learn how large real-world software systems and C++ projects are split cleanly across multiple directories and files.

---

## 🧒 Kid-Friendly Analogy: The Master Builder's Sorting Chest vs The Giant Junk Pile
Imagine you receive a 5,000-piece LEGO Star Wars Millennium Falcon:
- **The Junk Pile Approach (Monolithic `main.cpp`):**  
  You dump all 5,000 bricks, tiny lasers, cockpit glass, and gears into one massive heap on the floor. When you need a 2-stud red brick, you spend 30 minutes rummaging through the pile. If your friend tries to help, your hands keep bumping into each other!
- **The Master Builder's Sorting Chest (Multi-File Architecture):**  
  - **`include/` (The Blueprints):** The instruction booklets that show what pieces exist and how they snap together.
  - **`src/` (The Workshop):** The actual brick assemblies built piece by piece.
  - **`tests/` (The Quality Inspection):** Making sure the wings don't fall off before display!

With a multi-file architecture, **Teammate A** can work on the engine (`turnstile_cpu.cpp`) while **Teammate B** works on the passenger line (`passenger_queue.cpp`) at the exact same time without ever touching each other's files!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Standard Industry C++ Directory Layout
Look at your Team Projects (`project1_transit_gate`, `project2_warehouse_robot`, `project3_hospital_triage`):
```
  project_root/
  ├── include/                    <-- Header files (.h): Public API Declarations
  │   ├── turnstile_cpu.h
  │   ├── passenger_queue.h
  │   └── types.h
  ├── src/                        <-- Source files (.cpp): Implementation Logic
  │   ├── turnstile_cpu.cpp
  │   ├── passenger_queue.cpp
  │   └── main.cpp
  ├── CMakeLists.txt              <-- CLion build blueprint
  ├── Makefile                    <-- Terminal automated build script
  └── test.sh                     <-- Self-test runner
```

### 2. Telling the Compiler Where Headers Live (`-I` flag)
When code in `src/main.cpp` includes `#include "turnstile_cpu.h"`, `g++` needs to know which folder to check:
```bash
g++ -Wall -std=c++17 -I./include src/turnstile_cpu.cpp src/main.cpp -o app
```
The `-I./include` flag tells the preprocessor: *"Look inside the `./include` folder whenever you encounter `#include "..."`"*!

### 3. The Power of Incremental Compilation
If you have 100 source files and only change 1 line in `src/turnstile_cpu.cpp`:
- With a monolithic file, you must recompile all 100,000 lines (takes 2 minutes).
- With modular object files, `make` only recompiles `turnstile_cpu.cpp` into `turnstile_cpu.o` (takes 0.1 seconds) and relinks!

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <string>

// Simulating components that live across multiple files in a real project
struct EngineSubsystem {
    std::string name = "Virtual 4-Register MicroCPU";
    bool statusOnline = true;
};

struct QueueSubsystem {
    std::string name = "Circular Passenger FIFO Queue";
    int currentWaiting = 12;
};

struct Coordinator {
    EngineSubsystem engine;
    QueueSubsystem queue;

    void printSystemStatus() {
        std::cout << "  [System Coordinator Overview]\n";
        std::cout << "    Component 1: " << engine.name 
                  << " (Status: " << (engine.statusOnline ? "ONLINE" : "OFFLINE") << ")\n";
        std::cout << "    Component 2: " << queue.name 
                  << " (Queue Size: " << queue.currentWaiting << " commuters)\n";
    }
};

int main() {
    std::cout << "Testing Multi-File System Coordination...\n\n";
    Coordinator system;
    system.printSystemStatus();
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/13_multi_file_project_architecture/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/13_multi_file_project_architecture
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
Navigate to `projects/project1_transit_gate` and examine how `include/` and `src/` are structured. Notice how `main.cpp` brings all the individual pieces together seamlessly!
