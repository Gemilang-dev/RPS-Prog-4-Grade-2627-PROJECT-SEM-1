# Lesson 07: Concurrency & Multithreading Mechanics

Welcome to Lesson 07! In this lesson, you will learn how modern computers run multiple tasks simultaneously using C++ multithreading.

---

## 🧒 Kid-Friendly Analogy: The Pizza Kitchen with Multiple Chefs
Imagine a busy Italian pizza restaurant on a Saturday night:
- **Single-Threaded Kitchen (1 Chef):**  
  Chef Mario has to roll the dough, wait 15 minutes, chop the mushrooms, grate the cheese, put the pizza into the stone oven, and wash the dishes. Customers wait 2 hours for a single pizza!
- **Multithreaded Kitchen (3 Chefs in Parallel):**  
  - **Chef A (Thread 1):** Rolls the dough crust.  
  - **Chef B (Thread 2):** Grates the cheese and prepares tomato sauce.  
  - **Chef C (Thread 3):** Slices the toppings and preheats the oven.  

All three chefs work at the exact same time!  
Before sliding the pizza into the oven, the head chef calls: *"Is everyone done with their prep work?"*  
In C++, waiting for your helpers to finish their job before moving forward is called **joining threads (`workerThread.join()`)**!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Threads vs Processes
- A **Process** is an entire running application with its own isolated virtual address space.
- A **Thread** is a lightweight execution stream *inside* a process. All threads in a process share the same global memory, Heap, and open file handles, but each thread has its own private **Stack**.

### 2. Modern C++ Multithreading API (`<thread>`)
```cpp
#include <thread>

void workerTask(int workerId) {
    // Code executed concurrently by the worker thread
}

int main() {
    // Spawn a new operating system thread
    std::thread t1(workerTask, 1);
    
    // Crucial: Wait for the thread to finish its job before main() exits!
    t1.join(); 
    return 0;
}
```

### 3. Why `join()` is Mandatory
If a `std::thread` object goes out of scope while its background thread is still running and neither `.join()` nor `.detach()` was called, C++ immediately terminates your entire program by calling `std::terminate()` to prevent memory corruption!

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void prepareIngredient(std::string taskName, int durationMs) {
    std::cout << "  [Chef Thread Started] " << taskName << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(durationMs));
    std::cout << "  [Chef Thread Finished] " << taskName << " ready!\n";
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 07: CONCURRENCY & MULTITHREADING DEMO\n";
    std::cout << "====================================================\n\n";

    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "Detected CPU Hardware Concurrency: " << cores << " core threads.\n\n";

    std::cout << "--- Spawning 3 Kitchen Chefs in Parallel ---\n";
    auto start = std::chrono::high_resolution_clock::now();

    std::thread chef1(prepareIngredient, "Rolling Pizza Dough", 150);
    std::thread chef2(prepareIngredient, "Grating Fresh Mozzarella", 100);
    std::thread chef3(prepareIngredient, "Slicing Pepperoni & Basil", 120);

    // Wait for all 3 threads to complete
    chef1.join();
    chef2.join();
    chef3.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> totalTime = end - start;

    std::cout << "\nAll ingredients ready! Total parallel kitchen time: " 
              << totalTime.count() << " ms\n";
    std::cout << "(Note: Notice the total time is ~150ms, NOT 150+100+120 = 370ms!)\n\n";

    std::cout << "[PASS] Multithreading demonstration completed successfully!\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/07_concurrency_and_multithreading_mechanics/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/07_concurrency_and_multithreading_mechanics
g++ -Wall -std=c++17 -pthread example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
What happens if you delete one of the `.join()` calls in `example.cpp`? Try commenting out `chef1.join();` and re-running. Observe how the program safely catches the termination!
