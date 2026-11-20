# Project 1: Smart Transit Ticket & Turnstile Gate Controller

**Target Audience:** High School Computer Science Students (Solo or Pairs)  
**Estimated Time:** 3–6 hours  
**Architecture:** 8 Modular C++ Files (Virtual CPU, FIFO Queue, LIFO Stack)

---

## 🚆 Real-World Inspiration
In bustling transit stations (subway, metro, rail), thousands of commuters tap transit cards every minute:
1. **FIFO (First-In, First-Out):** Commuters enter the turnstile lane in arrival sequence.
2. **LIFO (Last-In, First-Out):** If a tap fails or a customer disputes an accidental charge, an undo/rollback mechanism refunds the most recent transaction first.
3. **Embedded Microcode Register Simulation:** Real hardware validates tickets in sub-millisecond cycles using simulated CPU registers (`AX`, `BX`, `CX`, `DX`) and condition flags (`ZeroFlag`, `SignFlag`).

---

## 📂 File Architecture
- `include/turnstile_cpu.h` & `src/turnstile_cpu.cpp` : Virtual register processor machine (Your assignment!).
- `include/passenger_queue.h` & `src/passenger_queue.cpp` : FIFO queue managing passenger line.
- `include/refund_stack.h` & `src/refund_stack.cpp` : LIFO stack managing transaction rollback.
- `include/turnstile_controller.h` & `src/turnstile_controller.cpp` : Coordinates CPU, queue, and stack.
- `src/main.cpp` : Main simulation driver.
- `src/test_runner.cpp` : 5-part automated unit test suite.

---

## 🛠️ Instructions for Students

1. Open `src/turnstile_cpu.cpp`.
2. Implement each `TODO` instruction by following the embedded clues.
3. **Which lessons should you consult for help?**
   - **Lesson 19:** `lessons/19_assembly_fundamentals_registers_and_instructions` — Explains registers (`AX`, `BX`), accumulator math (`ADD`, `SUB`), status flags (`CMP`), and conditional jumps (`JGE`, `JL`).
   - **Lesson 14:** `lessons/14_separating_declarations_and_definitions` — Explains how to implement functions declared in `.h` files inside `.cpp` files.
   - **Lesson 17:** `lessons/17_data_structures_fifo_queues` — Explains how the commuter FIFO queue works.
   - **Lesson 18:** `lessons/18_data_structures_lifo_stacks` — Explains how the transaction rollback LIFO stack operates.
   - **Lesson 20:** `lessons/20_automated_builds_and_makefiles` — Explains the build system.

---

## 🧪 Testing Your Code

### In Terminal:
```bash
# Run the automated test suite
bash test.sh

# Or compile manually with make
make all
./transit_gate
```

### In CLion:
1. Open this folder in CLion (`File -> Open...`).
2. Select `transit_test` from the run configuration dropdown and click **Run (Shift + F10)** to execute self-tests.
3. Select `transit_gate` and click **Run** to view the full turnstile simulation.
