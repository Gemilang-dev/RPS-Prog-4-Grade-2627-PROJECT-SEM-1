# Lesson 03: Git & GitHub for C++ Systems Programming

Welcome to Lesson 03! In this lesson, you will learn how to track changes, collaborate in teams, and use Git and GitHub effectively for systems programming.

---

## 🧒 Kid-Friendly Analogy: Video Game Save Slots & Cloud Co-Op
Imagine playing an epic adventure video game like Minecraft or Zelda:
1. **Save Checkpoints (`git commit`):**  
   Whenever you find a diamond or defeat a dungeon boss, you save your game with a quick note: *"Saved at Level 5 with magic key"*. If your character accidentally falls into lava later, you can always reload an older save!
2. **Alternate Timelines / Experiment Slots (`git branch`):**  
   What if you want to try an experimental potion without ruining your safe main game? You make a separate branch! If it works, you merge it back into your main save. If it fails, you delete the branch and nothing is damaged!
3. **Multiplayer Cloud Sync (`git push` / `git pull`):**  
   When working in pairs on your team project, you upload your commits to GitHub so your teammate can pull your changes onto their computer.
4. **The Trash Bin (`.gitignore`):**  
   You wouldn't save temp files, battery stats, or temporary screen screenshots into your game save file. Similarly, in C++, you **never** commit compiled binary files (`.o`, `.exe`, `app`) because your teammate's computer will compile its own fresh binaries!

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. The Three States of Git
```
  [Working Directory]  ──(git add)──>  [Staging Area / Index]  ──(git commit)──>  [Local Repository (.git)]
         │                                                                                 │
         └──────────────────────────────(git push)─────────────────────────────────────────▼
                                                                                   [GitHub Remote]
```

### 2. Essential Git Workflow for C++ Developers
```bash
# 1. Check which files were modified
git status

# 2. Stage specific C++ source and header files
git add src/turnstile_cpu.cpp include/turnstile_cpu.h

# 3. Create a clear, descriptive commit message
git commit -m "feat(cpu): implement MOV_AX and comparison flags"

# 4. Push branch to GitHub for your team partner to review
git push origin feature/cpu-logic
```

### 3. Crucial `.gitignore` Rules for C++
Never commit compiled artifacts or IDE configuration folders:
```gitignore
# Object and library files
*.o
*.obj
*.so

# Executables
*.exe
*.out
app

# CMake build folders
build/
cmake-build-*/
.idea/
```

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
#include <iostream>
#include <vector>
#include <string>

struct Commit {
    std::string hash;
    std::string message;
    std::string author;
};

int main() {
    std::cout << "Simulating Git Commit History for C++ Systems Team...\n\n";

    std::vector<Commit> history = {
        {"7f8b91a", "feat: initialize modular project architecture and headers", "Alice"},
        {"c4d2e01", "feat(cpu): implement arithmetic register instructions", "Bob"},
        {"a1b3c5d", "fix(queue): correct boundary check on empty dequeue", "Alice"},
        {"9e8d7c6", "test: add automated unit tests for ALU verification", "Bob"}
    };

    std::cout << "--- Git Log (--oneline --graph) ---\n";
    for (const auto& c : history) {
        std::cout << " * [" << c.hash << "] " << c.message << " (" << c.author << ")\n";
    }

    std::cout << "\n[PASS] All 4 commits tracked and verified.\n";
    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/03_git_and_github_for_cpp/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/03_git_and_github_for_cpp
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In your terminal, run `git status` in this repository to see how Git tracks your files. Notice which files are tracked and which are excluded by `.gitignore`!
