# Lesson 19: Assembly Fundamentals: Registers, Instructions & Flags

Welcome to Lesson 19! This is the **most crucial lesson** in the entire curriculum for completing your assignments in **Project 1** (`turnstile_cpu.cpp`), **Project 2** (`robot_alu.cpp`), and **Project 3** (`vitals_cpu.cpp`).

---

## 🧒 Kid-Friendly Analogy: The Chef's 4 Small Prep Bowls & Pocket Calculator
Imagine a master chef cooking in a giant restaurant kitchen:
- The giant walk-in storage refrigerator in the back of the building is **RAM (Random Access Memory)**. It holds billions of bytes of data, but walking back and forth to the refrigerator takes forever.
- Right on the cutting board directly under the chef's hands are **4 small shiny metal bowls**:
  - **Bowl AX (The Accumulator Bowl):** Where the chef measures and mixes ingredients (`AX`). All basic arithmetic happens here!
  - **Bowl BX (The Base Bowl):** Holds the base recipe threshold or limit (`BX`).
  - **Bowl CX (The Counter / Multiplier Bowl):** Holds loop counts, discount divisors, or priority factors (`CX`).
  - **Bowl DX (The Destination / Result Bowl):** Where the chef places the final calculated result (`DX`).

Because these bowls are right under the chef's fingertips, reaching into Bowl AX takes **less than 1 nanosecond**!  
In real computer hardware, these ultra-fast scratchpads inside the CPU are called **Registers**!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. The Core Assembly Instructions
In x86 assembly and in our virtual project CPUs, instructions manipulate registers directly:

| Instruction | What It Does | C++ Equivalent in Your Project |
| :--- | :--- | :--- |
| `MOV AX, val` | Copies a value into register AX | `AX = val;` |
| `MOV BX, val` | Copies a value into register BX | `BX = val;` |
| `ADD AX, val` | Adds value to accumulator AX | `AX += val;` |
| `SUB AX, val` | Subtracts value from accumulator AX | `AX -= val;` |
| `MUL CX, factor` | Multiplies register CX by a factor | `CX *= factor;` |
| `CMP AX, BX` | Compares AX with BX and sets status flags | Sets `ZeroFlag` and `SignFlag` |

### 2. How the CPU Compares Numbers (`CMP` & Condition Flags)
The CPU compares two numbers by internally subtracting them (`AX - BX`) and checking the result:
- **`ZeroFlag` (ZF):** Set to `true` if `AX == BX` (the difference is exactly zero).
- **`SignFlag` (SF):** Set to `true` if `AX < BX` (the subtraction resulted in a negative number).
- **`OverloadFlag` / `DangerFlag`:** Set to `true` if `AX > BX` (exceeded the safety threshold).

```cpp
void TurnstileCPU::CMP_AX_BX() {
    ZeroFlag = (AX == BX);
    SignFlag = (AX < BX); // True if balance is less than required fare!
}
```

### 3. Conditional Branching (Jumps)
Based on the status flags, the CPU makes decisions:
- **`JGE` (Jump if Greater or Equal):**  
  If `SignFlag == false` (balance $\ge$ fare), commuter is allowed through:
  ```cpp
  bool TurnstileCPU::JGE_OPEN() {
      if (!SignFlag) {
          CX = 1; // Signal open
          GateReg = 1;
          return true;
      }
      return false;
  }
  ```
- **`JL` (Jump if Less):**  
  If `SignFlag == true` (balance $<$ fare), gate remains locked:
  ```cpp
  bool TurnstileCPU::JL_DENY() {
      if (SignFlag) {
          CX = 0; // Signal locked
          GateReg = 0;
          return true;
      }
      return false;
  }
  ```
- **`JLE` (Jump if Less or Equal):**  
  Used in **Project 2** to accept parcels within the robot arm limit (`weight <= limit`), and in **Project 3** for stable patients (`JLE_STABLE()`).
- **`JG` (Jump if Greater):**  
  Used in **Project 2** to reject overweight packages (`weight > limit`), and in **Project 3** to trigger emergency Code Red triage (`JG_CRITICAL()`).

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>

struct VirtualMicroCpu {
    int AX = 0; // Accumulator
    int BX = 0; // Base Limit
    int CX = 0; // Multiplier / Status
    int DX = 0; // Output
    bool ZeroFlag = false;
    bool SignFlag = false;

    void MOV_AX(int val) { AX = val; }
    void MOV_BX(int val) { BX = val; }
    void ADD_AX(int val) { AX += val; }
    void SUB_AX(int val) { AX -= val; }

    void CMP() {
        ZeroFlag = (AX == BX);
        SignFlag = (AX < BX);
    }

    bool JGE() { return !SignFlag; }
    bool JL()  { return SignFlag; }
};

int main() {
    VirtualMicroCpu cpu;

    // Simulate Commuter Card: Balance $5.00, Fare $2.50
    cpu.MOV_AX(500);
    cpu.MOV_BX(250);
    cpu.CMP();

    std::cout << "Testing CPU Register Machine:\n";
    std::cout << "  Balance: $" << cpu.AX / 100.0 << " | Fare: $" << cpu.BX / 100.0 << "\n";
    std::cout << "  SignFlag (Insufficient?): " << (cpu.SignFlag ? "YES" : "NO") << "\n";
    std::cout << "  JGE (Gate Open?): " << (cpu.JGE() ? "OPEN GRANTED" : "DENIED") << "\n";

    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/19_assembly_fundamentals_registers_and_instructions/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/19_assembly_fundamentals_registers_and_instructions
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Direct Connection to Your Team Project!
Use this exact register manipulation and flag pattern to complete:
- **Project 1:** `projects/project1_transit_gate/src/turnstile_cpu.cpp`
- **Project 2:** `projects/project2_warehouse_robot/src/robot_alu.cpp`
- **Project 3:** `projects/project3_hospital_triage/src/vitals_cpu.cpp`
