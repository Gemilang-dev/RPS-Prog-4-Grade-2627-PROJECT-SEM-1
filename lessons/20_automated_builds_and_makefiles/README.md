# Lesson 20: Automated Builds & Makefiles

Welcome to Lesson 20! In this lesson, you will learn how developers automate complex multi-file compilation using Makefiles and build automation tools.

---

## 🧒 Kid-Friendly Analogy: The Smart Toy Factory Assembly Line
Imagine you own a toy factory that makes wooden toy race cars:
- **The Exhausting Way:**  
  Every morning, you hand-carve 4 wooden wheels, hand-sand the chassis, paint the car red, and screw in the axles. If you only changed the color of the steering wheel, you throw everything in the trash and re-carve all 4 wheels from scratch. You are exhausted by noon!
- **The Smart Robot Assembly Line (A Makefile):**  
  You give a smart helper robot a list of instructions:
  - Rule 1: *"Only carve a new wheel if the wood piece changed!"* (`wheel.o: wheel.cpp`)
  - Rule 2: *"Only repaint the chassis if the paint color changed!"* (`chassis.o: chassis.cpp`)
  - Rule 3: *"When all parts are ready, assemble the car!"* (`all: car`)
  - Rule 4: *"Sweep up the sawdust when asked!"* (`make clean`)

When you press the start button (`make`), the robot looks at the clocks on each piece. If the wheels haven't changed since yesterday, the robot **skips** them completely! Your build finishes in 0.2 seconds!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Anatomy of a Makefile Rule
Every Makefile rule consists of three components:
```makefile
target: prerequisites
	recipe
```
> ⚠️ **CRITICAL MAKEFILE SYNTAX RULE:**  
> The indentation before `recipe` **MUST be a real TAB character (`\t`)**, NOT 4 spaces! If you use spaces, `make` will fail with `*** missing separator. Stop.`!

### 2. Powerful Automatic Variables
Make provides shorthand variables so you don't repeat filenames:
- `$@` : Represents the **Target** file name.
- `$^` : Represents **All Prerequisites**.
- `$<` : Represents the **First Prerequisite**.

```makefile
# Example from projects/project1_transit_gate/Makefile:
transit_gate: src/main.o src/turnstile_cpu.o
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
```

### 3. Phony Targets (`.PHONY`)
Commands like `clean` and `test` don't produce a physical file named `clean` on disk. We label them as `.PHONY` so `make` always executes their commands:
```makefile
.PHONY: all clean test

clean:
	rm -f src/*.o transit_gate
```

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <vector>
#include <string>

struct BuildTarget {
    std::string target;
    std::vector<std::string> dependencies;
    bool needsRebuild;
};

int main() {
    std::cout << "Simulating Makefile Dependency Graph & Incremental Build...\n\n";

    std::vector<BuildTarget> rules = {
        {"src/turnstile_cpu.o", {"src/turnstile_cpu.cpp", "include/turnstile_cpu.h"}, true},
        {"src/passenger_queue.o", {"src/passenger_queue.cpp", "include/passenger_queue.h"}, false},
        {"src/main.o", {"src/main.cpp", "include/turnstile_cpu.h"}, false},
        {"transit_gate", {"src/turnstile_cpu.o", "src/passenger_queue.o", "src/main.o"}, true}
    };

    for (const auto& r : rules) {
        if (r.needsRebuild) {
            std::cout << "  [MAKE: RECOMPILE] Target `" << r.target 
                      << "` is out of date. Executing compiler recipe...\n";
        } else {
            std::cout << "  [MAKE: UP TO DATE] Target `" << r.target 
                      << "` timestamp unchanged. Skipping compilation.\n";
        }
    }

    std::cout << "\nIncremental build completed in 0.14 seconds!\n\n";
    std::cout << "[PASS] Build automation graph verified successfully.\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/20_automated_builds_and_makefiles/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/20_automated_builds_and_makefiles
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In your terminal, navigate to `projects/project1_transit_gate`, run `make all`, observe the compilation output, and then run `make clean` to see how the Makefile cleans up your workspace!
