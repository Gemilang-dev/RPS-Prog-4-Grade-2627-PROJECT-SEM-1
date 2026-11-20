# Complete Guide: Running C++ via Terminal & Anatomy of Comments

This guide is designed to help students understand how the computer transforms raw C++ source code into an executable program that runs in the terminal.

---

## 1. Stages of the C++ Compilation Pipeline

When you execute the command `g++ main.cpp -o main`, four stages happen behind the scenes:

```text
[main.cpp]
    │
    ▼ (1) Preprocessor (cpp)
    │   - Strips away all comments (// and /* */)
    │   - Resolves directives (#include, #define)
    ▼
[Clean Code Without Comments]
    │
    ▼ (2) Compiler (cc1plus)
    │   - Validates C++ syntax
    │   - Translates into Assembly language (.s)
    ▼
[Assembly Code]
    │
    ▼ (3) Assembler (as)
    │   - Converts assembly instructions into Machine Code / Object File (.o)
    ▼
[Object File (.o)]
    │
    ▼ (4) Linker (ld)
    │   - Resolves external references and standard libraries (iostream, etc.)
    │   - Produces the final executable binary (e.g., ./main)
    ▼
[Executable Binary]
```

---

## 2. Basic Terminal Commands

### A. Simple Compilation
```bash
g++ main.cpp -o main
```
- `g++` : Invokes the GNU C++ compiler.
- `main.cpp` : The source code file.
- `-o main` : Output flag specifying the binary file name. If omitted, the compiler outputs `a.out` (on Linux/macOS) or `a.exe` (on Windows).

### B. Running the Executable
On Linux / macOS:
```bash
./main
```
> **Why `./`?**
> In Unix-like systems, the shell searches for commands in directories listed in the `$PATH` environment variable. For security reasons, the current directory (`.`) is not in `$PATH`. The `./` explicitly tells the shell: *"Execute the binary file named `main` located right here in the current folder."*

On Windows PowerShell:
```powershell
.\main.exe
```

---

## 3. Essential Compiler Flags

| Flag | Function & Benefits | Example Usage |
|---|---|---|
| `-Wall` | Enables all standard compiler warnings. Catches unused variables, type mismatches, and potential bugs early. | `g++ main.cpp -Wall -o main` |
| `-Wextra` | Enables additional, stricter warnings beyond `-Wall`. | `g++ main.cpp -Wall -Wextra -o main` |
| `-std=c++17` | Instructs the compiler to enforce the ISO C++17 standard (structured bindings, `std::optional`, `std::filesystem`). | `g++ main.cpp -std=c++17 -o main` |
| `-O2` | Enables performance optimizations (produces faster assembly output). | `g++ main.cpp -O2 -o main` |
| `-g` | Embeds debugging symbols for use with debuggers like `gdb` or `lldb`. | `g++ main.cpp -g -o main` |

---

## 4. Chaining Commands with `&&`

Instead of running two commands separately:
1. `g++ main.cpp -Wall -o main`
2. `./main`

Combine them into one clean, efficient line:
```bash
g++ main.cpp -Wall -std=c++17 -o main && ./main
```
**Why `&&` instead of `;`?**
- The `&&` operator checks the exit code of the first command.
- If compilation **fails** (due to a syntax error), the shell **halts immediately** and does not run the stale previous executable.
- Using `;` runs the second command regardless of errors, which often confuses beginners.

---

## 5. Anatomy of C++ Comments

Comments are human-readable explanations written for programmers and completely ignored by the compiler.

### A. Single-Line Comment
Starts with `//`. All text following `//` until the end of the line is treated as a comment.
```cpp
// This is a single-line comment
int age = 17; // Comment alongside code
```

### B. Multi-Line / Block Comment
Starts with `/*` and ends with `*/`. Can span multiple lines.
```cpp
/*
   This is a multi-line comment.
   Used for longer explanations or temporarily
   disabling blocks of code during debugging.
*/
```

### C. The Fatal Trap: Nested Block Comments
In C++, block comments `/* ... */` **CANNOT BE NESTED**!
```cpp
/* Outer comment begins
   /* Inner comment? */ <-- The compiler sees this */ as the end of the outer comment!
   This text is now treated as REAL C++ CODE! */ <-- ERROR: syntax error
*/
```
**Technical Reason:** The compiler scans sequentially for the first `*/` delimiter. Once encountered, comment mode immediately terminates.

### D. Documentation Comments (Doxygen Style)
The industry standard format for documenting classes and functions:
```cpp
/**
 * @brief Computes integer exponentiation.
 * @param base The base number.
 * @param exponent The non-negative power exponent.
 * @return The result of base^exponent.
 */
long long power(int base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
```

### E. Do Comments Increase the Executable Binary Size?
**NO.**
During the Preprocessing phase, the C++ preprocessor replaces every comment with a single whitespace character. Comments never exist in the compiled machine code binary and consume zero CPU memory or runtime performance.
