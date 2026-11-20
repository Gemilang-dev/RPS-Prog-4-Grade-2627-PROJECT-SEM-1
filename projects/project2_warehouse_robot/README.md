# Project 2: Warehouse Robot & Parcel Dispatcher

**Target Audience:** High School Computer Science Students (Solo or Pairs)  
**Estimated Time:** 3–6 hours  
**Architecture:** 8 Modular C++ Files (ALU, Conveyor FIFO, Pallet LIFO)

---

## 📦 Real-World Inspiration
In modern automated fulfillment warehouses (Amazon, DHL, FedEx):
1. **FIFO (First-In, First-Out):** Parcels arrive on the conveyor belt in arrival order.
2. **LIFO (Last-In, First-Out):** Accepted packages are placed onto a dispatch pallet. To unload or inspect, packages must be removed in reverse order (top of the pallet first).
3. **Robotic ALU Register Simulation:** The robotic arm controller computes payload limits and priority multipliers using microcode registers (`AX`, `BX`, `CX`, `DX`) and condition flags (`OverloadFlag`, `MatchFlag`).

---

## 📂 File Architecture
- `include/robot_alu.h` & `src/robot_alu.cpp` : Virtual robot arithmetic logic unit (Your assignment!).
- `include/conveyor_fifo.h` & `src/conveyor_fifo.cpp` : FIFO queue managing incoming parcel belt.
- `include/pallet_lifo.h` & `src/pallet_lifo.cpp` : LIFO stack managing dispatch pallet loading.
- `include/dispatcher_controller.h` & `src/dispatcher_controller.cpp` : Coordinates conveyor, arm ALU, and pallet.
- `src/main.cpp` : Main warehouse dispatch simulation.
- `src/test_runner.cpp` : 5-part automated unit test suite.

---

## 🛠️ Instructions for Students

1. Open `src/robot_alu.cpp`.
2. Implement each `TODO` instruction by following the embedded clues.
3. **Which lessons should you consult for help?**
   - **Lesson 19:** `lessons/19_assembly_fundamentals_registers_and_instructions` — Explains registers, multiplication (`MUL`), comparison (`CMP`), and conditional branching (`JLE`, `JG`).
   - **Lesson 14:** `lessons/14_separating_declarations_and_definitions` — Explains how to implement functions declared in `.h` files inside `.cpp` files.
   - **Lesson 17:** `lessons/17_data_structures_fifo_queues` — Explains conveyor FIFO queue operation.
   - **Lesson 18:** `lessons/18_data_structures_lifo_stacks` — Explains pallet LIFO stack mechanics.
   - **Lesson 20:** `lessons/20_automated_builds_and_makefiles` — Explains compilation via Makefile.

---

## 🧪 Testing Your Code

### In Terminal:
```bash
# Run the automated test suite
bash test.sh

# Or compile manually with make
make all
./warehouse_robot
```

### In CLion:
1. Open this folder in CLion (`File -> Open...`).
2. Select `robot_test` from the run configuration dropdown and click **Run (Shift + F10)** to execute self-tests.
3. Select `warehouse_robot` and click **Run** to view the full dispatch simulation.
