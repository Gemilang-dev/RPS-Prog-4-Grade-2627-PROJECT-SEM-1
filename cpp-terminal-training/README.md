# Self-Paced Training: C++ Terminal Workflow & Comment Mechanics

Welcome to the self-paced warmup training module for compiling and running C++ programs directly from the terminal, as well as mastering comment syntax and compiler preprocessor behavior.

> 💡 **Stress-Free Learning (No Grades)**:
> This module is purely designed for practice, foundational confidence, and self-assessment. There are no penalty scores. The focus is mastering the terminal, the `g++` compiler pipeline, and proper C++ code documentation.

---

## 📁 Directory Structure

- `terminal_cpp_guide.md` : Comprehensive guide explaining the 4 compilation pipeline stages, `g++` flags, execution prefixes, and comment anatomy.
- `student_questions.html` : Offline-first HTML interactive practice form with self-check feedback and `.json` export.
- `verify_answers.sh` : Terminal verification tool that analyzes your `answers.json` and prints instant constructive guidance.
- `evaluate_submissions.sh` : Instructor automation script to evaluate multiple student submissions in batch.
- `sample_student_answers.json` : Reference answer file showing ideal answers and formatting.
- `sample_code/` : Hands-on code files to compile and run locally:
  - `hello.cpp` : First modern C++ program.
  - `calculator.cpp` : Interactive standard I/O terminal program.
  - `comment_demo.cpp` : Anatomy of single-line, multi-line, and Doxygen documentation comments.

---

## 🚀 Student Learning Flow

### Step 1: Open the Interactive HTML Form
1. Double click or open `student_questions.html` in any browser (Chrome, Firefox, Safari, Edge). It works 100% offline without internet.
2. Read and answer the 9 questions regarding terminal compilation, flags, and comment rules.
3. Click **"Check My Understanding"** to get instant feedback.
4. Click **"Download answers.json"** and save the file into this `cpp-terminal-training` folder.

### Step 2: Verify in Terminal
Open your terminal in this directory and run:
```bash
chmod +x verify_answers.sh
./verify_answers.sh
```

If you prefer answering directly in the terminal without opening a browser:
```bash
./verify_answers.sh --interactive
```

### Step 3: Practice Compiling Sample Programs
Navigate to the `sample_code/` directory and test your skills:
```bash
cd sample_code

# 1. Compile hello world
g++ hello.cpp -Wall -std=c++17 -o hello && ./hello

# 2. Compile and run calculator
g++ calculator.cpp -Wall -Wextra -std=c++17 -o calculator && ./calculator

# 3. Test comment demo
g++ comment_demo.cpp -Wall -o comment_demo && ./comment_demo
```
