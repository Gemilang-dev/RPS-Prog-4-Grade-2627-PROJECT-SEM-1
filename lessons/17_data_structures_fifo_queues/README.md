# Lesson 17: Data Structures: FIFO Queues

Welcome to Lesson 17! In this lesson, you will master the **FIFO (First-In, First-Out) Queue** data structure, which powers the intake pipeline in all 3 Team Projects!

---

## 🧒 Kid-Friendly Analogy: The Ice Cream Truck Line on a Hot Summer Day
Imagine an ice cream truck rings its musical bell right next to the school playground:
- **Kid 1 (Alice):** Arrives first. She stands right at the front of the window.
- **Kid 2 (Bob):** Arrives second. He stands in line behind Alice.
- **Kid 3 (Charlie):** Arrives third. He stands behind Bob.

When the ice cream vendor scoops the first chocolate ice cream cone, who receives it?  
🍦 **Alice receives it first!**  
After Alice walks away with her cone, Bob is now at the front of the line.

It would be completely unfair if Charlie sneaked to the front of the line!  
This fair, orderly rule is called **FIFO: First-In, First-Out**!  
The very first person who arrives in line is the very first person served.

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Anatomy of a Queue
A Queue is a linear data structure that operates strictly on two ends:
```
  Enqueue (push_back)                                             Dequeue (pop_front)
  ───────────────────> [ Charlie ] ──> [ Bob ] ──> [ Alice ] ───>
                             ▲                        ▲
                           (BACK)                  (FRONT)
```
- **`enqueue(item)` / `push(item)`:** Inserts a new element at the **Back (Tail)** of the queue ($O(1)$ constant time).
- **`dequeue()` / `pop()`:** Removes and returns the element at the **Front (Head)** of the queue ($O(1)$ constant time).
- **`front()` / `peek()`:** Inspects the front element without removing it.
- **`isEmpty()`:** Returns `true` if no elements remain.

### 2. How Queues Drive Your Team Projects
Look at how each of our 3 projects uses a FIFO Queue:
1. **Project 1 (Transit Gate):** `PassengerQueue` ensures commuters are processed through the turnstile gate in the exact order they arrive at the station.
2. **Project 2 (Warehouse Robot):** `ConveyorFIFO` streams incoming parcels from the delivery truck to the robot arm sequentially.
3. **Project 3 (Hospital Triage):** `ERQueue` admits incoming emergency patients sequentially at the check-in desk before vitals scanning.

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <queue>
#include <string>

struct Passenger {
    std::string name;
    int balanceCents;
};

int main() {
    std::cout << "Testing FIFO Passenger Queue Operations...\n\n";

    std::queue<Passenger> transitLine;

    // Enqueue passengers in arrival sequence (FIFO)
    std::cout << "--- 1. Enqueueing Passengers (Arrival Order) ---\n";
    transitLine.push({"Alice", 500});
    std::cout << "  [+ Enqueued] Alice ($5.00)\n";
    transitLine.push({"Bob", 250});
    std::cout << "  [+ Enqueued] Bob ($2.50)\n";
    transitLine.push({"Charlie", 150});
    std::cout << "  [+ Enqueued] Charlie ($1.50)\n\n";

    // Dequeue passengers through the turnstile gate
    std::cout << "--- 2. Dequeueing Passengers at Turnstile (FIFO Serving) ---\n";
    while (!transitLine.empty()) {
        Passenger current = transitLine.front(); // Peek at front
        transitLine.pop();                      // Remove front
        std::cout << "  -> Serving Commuter: " << current.name 
                  << " (Card Balance: $" << (current.balanceCents / 100.0) << ")\n";
    }

    std::cout << "\nQueue is now empty. All commuters processed in strict arrival order!\n\n";
    std::cout << "[PASS] FIFO Queue verified successfully.\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/17_data_structures_fifo_queues/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/17_data_structures_fifo_queues
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In `example.cpp`, enqueue a fourth passenger named `"Diana"` with a balance of `750` cents. Run the program and verify that Diana is served fourth, right after Charlie!
