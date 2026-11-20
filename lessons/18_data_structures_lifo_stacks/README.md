# Lesson 18: Data Structures: LIFO Stacks & Undo Rollbacks

Welcome to Lesson 18! In this lesson, you will master the **LIFO (Last-In, First-Out) Stack** data structure, which powers undo/rollback mechanisms in all 3 Team Projects!

---

## 🧒 Kid-Friendly Analogy: The Cafeteria Lunch Trays & The Pancake Stack
Imagine you are at the school cafeteria at lunchtime:
- The lunch worker stacks clean plastic trays into the tray dispenser:
  - **Tray 1** is placed at the bottom.
  - **Tray 2** is placed on top of Tray 1.
  - **Tray 3** is placed on the very top!
- When you walk up to get your food, which tray do you take?  
  🥞 **You take Tray 3—the one on the very top!**

You cannot pull Tray 1 from the bottom without knocking the whole pile over!  
The **LAST** tray placed on the stack is the **FIRST** tray taken off!  
This is called **LIFO: Last-In, First-Out**!

### Why is LIFO the secret behind "Undo" (`Ctrl + Z`)?
Whenever you type in an editor or play a game, your computer pushes your recent actions onto a LIFO stack. When you hit **Undo (`Ctrl + Z`)**, the computer pops the **most recent action first** to reverse it!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Anatomy of a Stack
A Stack only allows modifications at one single point called the **Top**:
```
        Push (add to top)             Pop (remove from top)
                │                              ▲
                ▼                              │
        ┌───────────────┐              ┌───────────────┐
  TOP ->│ Action 3      │              │ Action 3      │ -> Popped first!
        ├───────────────┤              ├───────────────┤
        │ Action 2      │              │ Action 2      │
        ├───────────────┤              ├───────────────┤
  BASE->│ Action 1      │              │ Action 1      │
        └───────────────┘              └───────────────┘
```
- **`push(item)`:** Places an item on the top of the stack ($O(1)$ constant time).
- **`pop()`:** Removes the item currently on top of the stack ($O(1)$ constant time).
- **`top()` / `peek()`:** Inspects the top item without removing it.
- **`empty()`:** Returns `true` if the stack contains zero items.

### 2. How Stacks Drive Your Team Projects
Look at how each of our 3 projects uses a LIFO Stack:
1. **Project 1 (Transit Gate):** `RefundStack` stores commuter fare payments. If a passenger's transfer fails, the system rolls back and refunds the most recent transaction first!
2. **Project 2 (Warehouse Robot):** `PalletLIFO` represents a wooden shipping pallet. Packages are stacked vertically; unloading requires removing the topmost package first!
3. **Project 3 (Hospital Triage):** `ActionStack` logs emergency medical treatments. If a patient develops a sudden allergy, the doctor immediately rolls back and reverses the most recent medication!

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <stack>
#include <string>

struct Transaction {
    std::string commuterName;
    int fareCents;
    std::string timestamp;
};

int main() {
    std::cout << "Testing LIFO Transaction Rollback Stack Operations...\n\n";

    std::stack<Transaction> rollbackStack;

    // 1. Push transactions onto the stack as they occur
    std::cout << "--- 1. Processing Transactions (Push onto LIFO Stack) ---\n";
    rollbackStack.push({"Alice", 250, "08:01 AM"});
    std::cout << "  [+ Push] Alice paid $2.50\n";
    rollbackStack.push({"Bob", 150, "08:03 AM"});
    std::cout << "  [+ Push] Bob paid $1.50\n";
    rollbackStack.push({"Charlie", 250, "08:05 AM"});
    std::cout << "  [+ Push] Charlie paid $2.50\n\n";

    // 2. Perform emergency rollback (reversing most recent transaction first)
    std::cout << "--- 2. Customer Dispute: Executing Undo Rollback (LIFO) ---\n";
    if (!rollbackStack.empty()) {
        Transaction last = rollbackStack.top(); // Inspect top
        rollbackStack.pop();                   // Pop top
        std::cout << "  [ROLLBACK REFUND] Refunding most recent tap: " 
                  << last.commuterName << " ($" << (last.fareCents / 100.0) 
                  << " returned!)\n";
    }

    std::cout << "\nRemaining transactions safely retained in stack.\n\n";
    std::cout << "[PASS] LIFO Rollback Stack verified successfully.\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/18_data_structures_lifo_stacks/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/18_data_structures_lifo_stacks
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In `example.cpp`, trigger two consecutive rollback operations. Verify that Charlie is refunded first, followed by Bob, leaving Alice in the stack!
