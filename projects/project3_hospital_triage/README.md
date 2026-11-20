# Project 3: Hospital Emergency Triage & Diagnostic Vital Monitor

**Target Audience:** High School Computer Science Students (Solo or Pairs)  
**Estimated Time:** 3–6 hours  
**Architecture:** 8 Modular C++ Files (Virtual CPU, FIFO Queue, LIFO Stack)

---

## 🏥 Real-World Problem Inspiration
In a high-intensity hospital Emergency Department (ED / ER), seconds matter:
1. **FIFO (First-In, First-Out):** Patients arrive at the triage intake reception and are checked in strictly in their arrival sequence.
2. **LIFO (Last-In, First-Out):** Clinical emergency treatments and administered medications are tracked in an undo/rollback stack so that doctors can instantly reverse the most recent treatment if an allergic reaction occurs.
3. **Diagnostic Microcode CPU Simulation:** Vital signs (Heart Rate in BPM, Blood Oxygen Saturation $\% SpO_2$) are analyzed in real time using simulated CPU registers (`AX`, `BX`, `CX`, `DX`) and condition flags (`DangerFlag`, `HypoxiaFlag`) to trigger emergency Code Red routing.

---

## 📂 File Architecture
- `include/vitals_cpu.h` & `src/vitals_cpu.cpp` : Virtual diagnostic CPU register machine (**Your assignment!**).
- `include/er_queue.h` & `src/er_queue.cpp` : FIFO queue managing incoming emergency patient line.
- `include/action_stack.h` & `src/action_stack.cpp` : LIFO stack managing medical treatment rollbacks.
- `include/triage_controller.h` & `src/triage_controller.cpp` : Coordinates CPU, patient queue, and action stack.
- `include/patient_types.h` : Data types (`Patient`, `VitalSigns`, `MedicalTreatment`).
- `src/main.cpp` : Main clinical simulation driver.
- `src/test_runner.cpp` : 5-part automated unit test suite.
- `CMakeLists.txt` & `Makefile` : Build configurations for CLion and command-line compilation.

---

## 🛠️ Instructions for Students

1. Open `src/vitals_cpu.cpp`.
2. Implement each `TODO` instruction (`TODO 1` through `TODO 7`) by following the embedded clues and function contracts.
3. **Which lessons should you consult for help?**
   - **Lesson 19:** `lessons/19_assembly_fundamentals_registers_and_instructions` — Explains registers (`AX`, `BX`, `CX`, `DX`), arithmetic instructions (`COMPUTE_SEVERITY`), comparison condition flags (`CMP_VITALS`), and conditional jumps (`JG_CRITICAL`, `JLE_STABLE`).
   - **Lesson 14:** `lessons/14_separating_declarations_and_definitions` — Explains how to implement member functions declared in `.h` header files inside corresponding `.cpp` source files.
   - **Lesson 17:** `lessons/17_data_structures_fifo_queues` — Explains how the emergency patient intake FIFO queue works.
   - **Lesson 18:** `lessons/18_data_structures_lifo_stacks` — Explains how the medical treatment rollback LIFO stack operates.
   - **Lesson 20:** `lessons/20_automated_builds_and_makefiles` — Explains the build system and CMake / Makefile targets.

---

## 🧪 Testing Your Code

### In CLion:
1. Open this directory or the root repository folder in CLion.
2. Select the `triage_test` run configuration from the top-right dropdown.
3. Click the green **Run (▶)** button to execute the 5-part test suite.
4. Select `hospital_triage` to run the full simulation demonstration!

### In Terminal:
```bash
# Run the automated test suite
bash test.sh

# Or compile manually with make
make all
./hospital_triage
```
