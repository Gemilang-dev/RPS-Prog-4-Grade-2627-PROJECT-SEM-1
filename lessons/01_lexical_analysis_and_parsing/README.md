# Lesson 01: Lexical Analysis & Parsing

Welcome to Lesson 01! In this lesson, you will discover how a compiler reads human-written C++ code and turns it into something a computer can understand.

---

## 🧒 Kid-Friendly Analogy: Reading a Storybook
Imagine you are reading a children's storybook:
> *"The red dragon breathed hot fire."*

To understand this sentence, your brain does two completely separate jobs:
1. **Word Recognition (Lexical Analysis / The Lexer):**  
   Your eyes scan individual letters: `t-h-e` $\rightarrow$ word: "The". `r-e-d` $\rightarrow$ word: "red". `d-r-a-g-o-n` $\rightarrow$ word: "dragon".  
   If you saw a word like `@#$%!`, you would stop and say: *"Wait, that isn't a valid word in our language!"* (That is a **Lexical Error**).
2. **Grammar Checking (Parsing / The Parser):**  
   Once you have the words, your brain checks if they follow grammar rules: `[Article] [Adjective] [Noun] [Verb] [Adjective] [Noun]`. This makes sense!  
   Now imagine reading: *"Breathed dragon the red fire hot."*  
   Every individual word is a real word, but the sentence structure is broken! That is a **Syntax Error**.

In C++, the **Lexer** turns raw text into **Tokens** (like keywords, variable names, numbers), and the **Parser** arranges those tokens into a **Syntax Tree** (grammar rules) to make sure your program makes sense!

---

## ⚙️ Under the Hood: Deep Technical Explanation

When you write `int total = price + 5;`, the compiler processes it in two distinct phases:

### Phase 1: Lexical Analysis (Scanner / Lexer)
- Reads the raw source code character-by-character from disk.
- Groups characters into meaningful chunks called **Lexemes** and categorizes them into **Tokens**:
  - `int` $\rightarrow$ `TOKEN_KEYWORD`
  - `total` $\rightarrow$ `TOKEN_IDENTIFIER`
  - `=` $\rightarrow$ `TOKEN_ASSIGN_OP`
  - `price` $\rightarrow$ `TOKEN_IDENTIFIER`
  - `+` $\rightarrow$ `TOKEN_PLUS_OP`
  - `5` $\rightarrow$ `TOKEN_INT_LITERAL`
  - `;` $\rightarrow$ `TOKEN_SEMICOLON`
- Drops unnecessary whitespace and comments.

### Phase 2: Syntactic Analysis (Parsing)
- Takes the stream of Tokens and verifies them against the formal grammar of C++.
- Builds an **Abstract Syntax Tree (AST)**:
```
           Assignment (=)
           /            \
    Identifier (total)   Binary Op (+)
                         /           \
               Identifier (price)   Literal (5)
```
- If you forget a semicolon `;` or type `int total = +;`, the lexer recognizes all tokens, but the parser fails with a **Syntax Error** because grammar rules were violated.

---

## 💻 Practical Code Example (`example.cpp`)

Here is an educational mini-tokenizer written in C++ that demonstrates how a compiler scans tokens and evaluates an expression:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

enum class TokenType { KEYWORD, IDENTIFIER, NUMBER, OPERATOR, SEMICOLON, END_OF_FILE };

struct Token {
    TokenType type;
    std::string text;
};

// Mini Lexer: Scans a line of code into Tokens
std::vector<Token> tokenize(const std::string& source) {
    std::vector<Token> tokens;
    size_t i = 0;
    while (i < source.size()) {
        if (std::isspace(source[i])) { i++; continue; }
        if (std::isdigit(source[i])) {
            std::string num;
            while (i < source.size() && std::isdigit(source[i])) num += source[i++];
            tokens.push_back({TokenType::NUMBER, num});
            continue;
        }
        if (std::isalpha(source[i])) {
            std::string id;
            while (i < source.size() && (std::isalnum(source[i]) || source[i] == '_')) id += source[i++];
            if (id == "int" || id == "return" || id == "if") tokens.push_back({TokenType::KEYWORD, id});
            else tokens.push_back({TokenType::IDENTIFIER, id});
            continue;
        }
        if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '=') {
            tokens.push_back({TokenType::OPERATOR, std::string(1, source[i++])});
            continue;
        }
        if (source[i] == ';') {
            tokens.push_back({TokenType::SEMICOLON, ";"});
            i++;
            continue;
        }
        i++;
    }
    tokens.push_back({TokenType::END_OF_FILE, "EOF"});
    return tokens;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open this repository in CLion.
2. Open `lessons/01_lexical_analysis_and_parsing/example.cpp`.
3. Right click inside `example.cpp` and select **Run 'example.cpp'** (or use the green Play arrow in the top toolbar).

### In Terminal:
```bash
cd lessons/01_lexical_analysis_and_parsing
g++ -Wall -std=c++17 example.cpp -o example
./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
Open `example.cpp`, find the test string in `main()`, and add a new expression like `"int score = bonus + 100;"`. Run the program again and see how the lexer identifies the new tokens!
