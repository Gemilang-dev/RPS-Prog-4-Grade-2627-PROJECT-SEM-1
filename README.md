# High School C++ Systems Programming & Assembly Curriculum

Welcome to the comprehensive, GitHub-ready **C++ Systems Programming & Assembly Projects Curriculum** designed specifically for high school computer science students!

> [!IMPORTANT]
> ### ⏰ Final Project Submission Deadline: **December 20**
> All project implementations, code comments, and automated test suite verifications must be completed and pushed to your GitHub repository by **December 20**.

> [!TIP]
> ### 🍴 Mandatory Student Workflow: Fork This Repository First!
> **DO NOT** attempt to clone and push directly to this central repository!
> 1. Click the **"Fork"** button in the top-right corner of this GitHub page to create your own copy under your personal GitHub account.
> 2. Clone your **forked** repository to your local computer:
>    ```bash
>    git clone https://github.com/<your-github-username>/RPS-Prog-4-Grade-2627-PROJECT-SEM-1.git
>    ```
> 3. Open your cloned project in **CLion** or VSCode.
> 4. Collaborate in pairs or individually, commit your work frequently, and push your commits to your fork on GitHub before the **December 20** deadline.

This curriculum demystifies how computer hardware, operating systems, compilers, and low-level data structures operate under the hood. Every lesson breaks down advanced engineering concepts using **intuitive real-world analogies that even an elementary school student can immediately grasp**, paired with real C++ code you can run and modify yourself.

---

## 🚀 Quick Setup: Preparing Your Environment

To write, compile, and debug C++ programs, you will need a modern C++ compiler (`g++` or `clang++`), `cmake`, and a professional Integrated Development Environment (IDE) like **JetBrains CLion**.

### 1. Download JetBrains CLion (Free for Students & Non-Commercial Use)
- **Official Download Link:** [https://www.jetbrains.com/clion/download/](https://www.jetbrains.com/clion/download/)

#### 💡 How to Get CLion 100% FREE:
JetBrains provides free access for learners and educators:
- **Option A: Non-Commercial License (Instant & Free):**  
  JetBrains makes CLion completely free for non-commercial learning, personal exploration, and homework!
  1. Download and install CLion from the link above.
  2. Launch CLion. When the license activation window appears, choose **"Non-commercial use"**.
  3. Sign in with or register a free JetBrains account.
  4. You now have full, unrestricted access to CLion for learning!
- **Option B: JetBrains Educational License:**  
  High school students and teachers can also apply for a free educational license using a school email address or via the [GitHub Student Developer Pack](https://education.github.com/pack) at [https://www.jetbrains.com/community/education/#students](https://www.jetbrains.com/community/education/#students).

---

### 2. Installing Compilers & Toolchains

#### 🐧 Linux (Ubuntu / Debian / Linux Mint):
Open your terminal and install the essential build tools:
```bash
sudo apt update
sudo apt install build-essential gdb cmake git -y
```

#### 🍎 macOS:
Open Terminal and install the Apple Command Line Tools and Homebrew CMake:
```bash
xcode-select --install
# If you have Homebrew installed:
brew install cmake
```

#### 🪟 Windows:
- **Option 1 (Recommended):** Install **WSL2 (Windows Subsystem for Linux)** with Ubuntu, and follow the Linux instructions above.
- **Option 2:** Install **Visual Studio Community** with the *"Desktop development with C++"* workload.
- **Option 3:** Install **MinGW-w64** via [MSYS2](https://www.msys2.org/).

---

## 📖 How to Read the Lesson Materials

Every lesson in the `lessons/` folder contains a detailed, standalone `README.md` guide:
- **On GitHub:** Simply click into any lesson folder (e.g., `lessons/01_lexical_analysis_and_parsing/`) on github.com. GitHub will render the README with full formatting and tables automatically.
- **In VSCode:** Open the lesson's `README.md` and press `Ctrl + Shift + V` (Windows/Linux) or `Cmd + Shift + V` (macOS) to open the Markdown Preview. You can also install the **Markdown Preview Enhanced** extension.
- **In CLion:** CLion has a built-in split-screen Markdown editor and live preview. Simply double-click any `README.md` to read the theory on the right while viewing code on the left!

---

## 📚 Complete Curriculum Roadmap (Lessons 01 – 20)

| Lesson | Topic | 🧒 Kid-Friendly Analogy | Unlocks Project |
| :---: | :--- | :--- | :---: |
| **[01](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/01_lexical_analysis_and_parsing/README.md)** | **Lexical Analysis & Parsing** | Reading a storybook: Words vs grammar rules | All Projects |
| **[02](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/02_terminal_compilation_and_comments/README.md)** | **Terminal Compilation & Comments** | Sticky notes on grandma's cookie recipe | All Projects |
| **[03](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/03_git_and_github_for_cpp/README.md)** | **Git & GitHub for Systems** | Video game save slots & cloud co-op | Team Projects |
| **[04](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/04_compiler_optimization_and_object_files/README.md)** | **Compiler Optimization & Object Files** | Doing math homework ahead of time | All Projects |
| **[05](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/05_linker_and_symbol_tables/README.md)** | **The Linker & Symbol Tables** | The scavenger hunt clues & missing puzzle piece | All Projects |
| **[06](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/06_os_execution_model_stack_vs_heap/README.md)** | **Stack vs Heap Memory Model** | Fast school backpack vs giant rented warehouse | Projects 1, 2, 3 |
| **[07](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/07_concurrency_and_multithreading_mechanics/README.md)** | **Concurrency & Multithreading** | The pizza kitchen with 3 chefs in parallel | Advanced Systems |
| **[08](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/08_thread_synchronization_and_mutex_lock/README.md)** | **Thread Synchronization & Mutex** | The single restroom wooden key at a busy cafe | Safe Concurrency |
| **[09](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/09_basic_preprocessor_directives/README.md)** | **Basic Preprocessor Directives** | The copy-paste typewriter robot assistant | All Projects |
| **[10](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/10_conditional_compilation_and_header_guards/README.md)** | **Header Guards & Conditional Builds** | Birthday party guest list & secret laser lights | Projects 1, 2, 3 |
| **[11](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/11_namespaces/README.md)** | **Namespaces in C++** | Two kids named "Leo" in different classrooms | All Projects |
| **[12](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/12_resolving_namespace_conflicts/README.md)** | **Resolving Namespace Conflicts** | Two toy boxes with a "RaceCar" in both | All Projects |
| **[13](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/13_multi_file_project_architecture/README.md)** | **Multi-File Project Architecture** | Master builder's sorting chest vs giant junk pile | Projects 1, 2, 3 |
| **[14](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/14_separating_declarations_and_definitions/README.md)** | **Separating Declarations & Definitions** | The restaurant menu vs the chef in the kitchen | ⭐ **Projects 1, 2, 3** |
| **[15](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/15_third_party_library_integration/README.md)** | **Third-Party Library Integration** | Buying a pre-made LEGO electric motor | Real-World C++ |
| **[16](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/16_configuring_include_paths_in_ide/README.md)** | **Configuring Include Paths in IDEs** | Programming your best friend's address into GPS | CLion & CMake |
| **[17](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/17_data_structures_fifo_queues/README.md)** | **Data Structures: FIFO Queues** | The ice cream truck line at recess | ⭐ **Projects 1, 2, 3** |
| **[18](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/18_data_structures_lifo_stacks/README.md)** | **Data Structures: LIFO Stacks & Undo** | Cafeteria tray stack & Ctrl+Z undo button | ⭐ **Projects 1, 2, 3** |
| **[19](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/19_assembly_fundamentals_registers_and_instructions/README.md)** | **Assembly Registers, CMP & Branching** | The chef's 4 small prep bowls & calculator | ⭐ **Projects 1, 2, 3** |
| **[20](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/lessons/20_automated_builds_and_makefiles/README.md)** | **Automated Builds & Makefiles** | The smart toy factory automated assembly line | Projects 1, 2, 3 |

---

## 🛠️ The 3 Capstone Team Projects

Students work in pairs or independently on one of the 3 real-world systems simulation projects. Each project simulates an embedded hardware controller combining a **Virtual Microcode CPU/ALU Register Machine**, a **FIFO intake queue**, and a **LIFO rollback stack**:

### 🚆 [Project 1: Smart Transit Ticket & Turnstile Gate Controller](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/projects/project1_transit_gate/README.md)
- **Assigned Student File:** `projects/project1_transit_gate/src/turnstile_cpu.cpp`
- **Key Concepts:** Registers `AX` (Balance), `BX` (Base Fare), `CX` (Tier Divisor), `DX` (Calculated Fare), condition flags (`ZeroFlag`, `SignFlag`), conditional gate opening (`JGE_OPEN`, `JL_DENY`), passenger FIFO line, rollback refund LIFO stack.
- **Embedded Clues:** Follow the `TODO` comments inside `src/turnstile_cpu.cpp` which directly reference Lesson 19, Lesson 14, and Lesson 17.

### 📦 [Project 2: Warehouse Robot & Parcel Dispatcher](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/projects/project2_warehouse_robot/README.md)
- **Assigned Student File:** `projects/project2_warehouse_robot/src/robot_alu.cpp`
- **Key Concepts:** Registers `AX` (Weight), `BX` (Arm Limit), `CX` (Priority Multiplier), `DX` (Shipping Energy), condition flags (`MatchFlag`, `OverloadFlag`), robotic dispatch branching (`JLE_ACCEPT`, `JG_REJECT`), conveyor belt FIFO queue, dispatch pallet LIFO stack.
- **Embedded Clues:** Follow the `TODO` comments inside `src/robot_alu.cpp` pointing directly to Lesson 19 and Lesson 14.

### 🏥 [Project 3: Hospital Emergency Triage & Diagnostic Vital Monitor](file:///home/ray/Downloads/c++-systems-curriculum-&-high-school-asssajkembly-projects/projects/project3_hospital_triage/README.md)
- **Assigned Student File:** `projects/project3_hospital_triage/src/vitals_cpu.cpp`
- **Key Concepts:** Registers `AX` (Heart Rate), `BX` (Danger Threshold), `CX` (Oxygen Saturation), `DX` (Computed Clinical Severity), clinical flags (`DangerFlag`, `HypoxiaFlag`), routing branches (`JG_CRITICAL` Code Red, `JLE_STABLE` Green), patient ER FIFO intake, medication allergy rollback LIFO stack.
- **Embedded Clues:** Follow the `TODO` comments inside `src/vitals_cpu.cpp` pointing directly to Lesson 19, Lesson 14, and Lesson 18.

---

## 🧪 How to Test and Verify Your Code

### Running Project Tests in CLion:
1. Open this repository root folder in CLion (`File -> Open...`).
2. In the top-right toolbar dropdown, choose any test target:
   - `transit_test` for Project 1
   - `robot_test` for Project 2
   - `triage_test` for Project 3
3. Click the green **Play (▶)** button or press `Shift + F10`!
4. Once all 5 automated unit tests pass, choose the main target (`transit_gate`, `warehouse_robot`, or `hospital_triage`) and run the full simulation!

### Running Tests in Terminal:
Navigate into your project folder and run:
```bash
# Example for Project 1:
cd projects/project1_transit_gate
bash test.sh

# Or compile manually with make:
make all
./transit_gate
```

---

