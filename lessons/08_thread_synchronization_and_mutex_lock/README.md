# Lesson 08: Thread Synchronization & Mutex Lock

Welcome to Lesson 08! In this lesson, you will learn how to protect shared data when multiple threads run simultaneously, preventing race conditions using Mutex locks.

---

## 🧒 Kid-Friendly Analogy: The Single Restroom Key at a Busy Cafe
Imagine a cozy cafe with 50 customers and **only one single restroom**:
- **Without a Lock (The Catastrophic Race Condition):**  
  Two people rush to the restroom door at the exact same millisecond and both twist the doorknob. They collide, spill coffee, and cause an embarrassing disaster!
- **With a Wooden Key (The Mutex Lock):**  
  The cafe hangs a wooden key on a hook by the counter.  
  1. Customer A grabs the key (`mutex.lock()`).  
  2. While Customer A is inside, Customer B must patiently wait outside.  
  3. When Customer A finishes, they put the key back on the hook (`mutex.unlock()`). Now Customer B can enter!

In C++, **MUTEX** stands for **Mut**ual **Ex**clusion. It guarantees that only **one thread** can touch sensitive shared data at a time!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. What is a Race Condition?
When two threads read and write to the same memory variable simultaneously without synchronization:
```
  Thread 1: Reads count (42) ──> Adds 1 (43) ──> Writes back (43)
  Thread 2: Reads count (42) ──> Adds 1 (43) ──> Writes back (43)
```
Even though both threads added 1, the final count is `43` instead of `44`! One increment was silently lost!

### 2. Using `std::mutex` and `std::lock_guard`
Never call `.lock()` and `.unlock()` manually if an exception could skip `.unlock()`, causing a permanent freeze (**Deadlock**).  
Instead, always use **`std::lock_guard` (RAII Lock)**:
```cpp
#include <mutex>

std::mutex mtx;
int sharedCounter = 0;

void safeIncrement() {
    // Lock is acquired when guard is constructed
    std::lock_guard<std::mutex> lock(mtx);
    sharedCounter++; 
    // Lock is automatically released when guard goes out of scope!
}
```

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex printMutex;
std::mutex bankMutex;
int sharedBankVault = 0;

void depositMoney(int customerId, int amount) {
    // Protect shared bank account with a mutex lock
    {
        std::lock_guard<std::mutex> lock(bankMutex);
        sharedBankVault += amount;
    }

    // Protect console output from overlapping text
    {
        std::lock_guard<std::mutex> printLock(printMutex);
        std::cout << "  Customer #" << customerId << " deposited $" << amount 
                  << " | New Vault Total: $" << sharedBankVault << "\n";
    }
}

int main() {
    std::vector<std::thread> customers;
    for (int i = 1; i <= 5; ++i) {
        customers.emplace_back(depositMoney, i, 100);
    }
    for (auto& t : customers) {
        t.join();
    }
    std::cout << "\nFinal Verified Vault Total: $" << sharedBankVault << "\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/08_thread_synchronization_and_mutex_lock/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/08_thread_synchronization_and_mutex_lock
g++ -Wall -std=c++17 -pthread example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In `example.cpp`, increase the number of customers to 100 with 10 parallel threads. Notice how `std::lock_guard` always keeps the final vault balance mathematically exact ($10,000)!
