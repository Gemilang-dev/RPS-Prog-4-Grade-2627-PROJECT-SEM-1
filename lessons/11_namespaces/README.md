# Lesson 11: Namespaces in C++

Welcome to Lesson 11! In this lesson, you will learn how to organize code and prevent naming collisions using C++ namespaces.

---

## 🧒 Kid-Friendly Analogy: Two Kids Named "Leo" in the Same School
Imagine a school with 500 students:
- In **Class 5A**, there is a boy named **Leo**.
- In **Class 5B**, there is another boy named **Leo**.

If the principal stands in the hallway and shouts: *"Hey, Leo, report to the office!"*, both boys stop and ask: *"Which Leo do you mean?"*  
To avoid confusion, the principal says:
- `Class5A::Leo` $\rightarrow$ Leo in Class 5A!
- `Class5B::Leo` $\rightarrow$ Leo in Class 5B!

In C++, **Namespaces** are labeled classrooms. Inside different namespaces, you can use the exact same variable or function names without causing any confusion!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Declaring a Namespace
```cpp
namespace TransitSystem {
    struct Controller {
        int activeGates = 4;
    };
    void reboot() { /* ... */ }
}

namespace WarehouseSystem {
    struct Controller {
        int activeRobots = 12;
    };
    void reboot() { /* ... */ }
}
```

### 2. The Scope Resolution Operator (`::`)
To access an item inside a namespace from outside, use double colons (`::`):
```cpp
TransitSystem::Controller tCtrl;
WarehouseSystem::Controller wCtrl;

TransitSystem::reboot();
```

### 3. Why You Should NEVER Put `using namespace std;` in Headers
Writing `using namespace std;` dumps hundreds of names (`std::min`, `std::max`, `std::queue`, `std::map`) into the global scope. If someone includes your header, their own functions might suddenly conflict with standard library names! Always write `std::cout`, `std::vector`, or use scoped `using` inside local function blocks.

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <string>

namespace Transit {
    class GateController {
    public:
        void openGate() {
            std::cout << "  [Transit::GateController] Turnstile barrier unlocked for commuter.\n";
        }
    };
}

namespace Warehouse {
    class GateController {
    public:
        void openGate() {
            std::cout << "  [Warehouse::GateController] Heavy cargo bay blast door opening.\n";
        }
    };
}

int main() {
    std::cout << "Testing C++ Namespaces...\n\n";

    Transit::GateController transitGate;
    Warehouse::GateController warehouseDoor;

    transitGate.openGate();
    warehouseDoor.openGate();

    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/11_namespaces/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/11_namespaces
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
Create a third namespace called `Hospital` with its own `GateController` that prints `[Hospital] Emergency ICU sliding doors open!` and call it from `main()`.
