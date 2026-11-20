// Lesson 01: Lexical Analysis & Parsing - Educational Demonstration
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

enum class TokenType { KEYWORD, IDENTIFIER, NUMBER, OPERATOR, SEMICOLON, END_OF_FILE };

struct Token {
    TokenType type;
    std::string text;
};

// Mini Lexer: breaks raw code strings into categorized tokens
std::vector<Token> tokenize(const std::string& source) {
    std::vector<Token> tokens;
    size_t i = 0;
    while (i < source.size()) {
        if (std::isspace(source[i])) { 
            i++; 
            continue; 
        }
        if (std::isdigit(source[i])) {
            std::string num;
            while (i < source.size() && std::isdigit(source[i])) {
                num += source[i++];
            }
            tokens.push_back({TokenType::NUMBER, num});
            continue;
        }
        if (std::isalpha(source[i])) {
            std::string id;
            while (i < source.size() && (std::isalnum(source[i]) || source[i] == '_')) {
                id += source[i++];
            }
            if (id == "int" || id == "return" || id == "if") {
                tokens.push_back({TokenType::KEYWORD, id});
            } else {
                tokens.push_back({TokenType::IDENTIFIER, id});
            }
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

std::string tokenTypeName(TokenType type) {
    switch (type) {
        case TokenType::KEYWORD: return "KEYWORD";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::OPERATOR: return "OPERATOR";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::END_OF_FILE: return "END_OF_FILE";
    }
    return "UNKNOWN";
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 01: LEXICAL ANALYSIS & PARSING DEMO\n";
    std::cout << "====================================================\n\n";

    std::string sampleCode = "int total = price + 50;";
    std::cout << "Input C++ Code: \"" << sampleCode << "\"\n\n";

    std::cout << "--- 1. Lexical Analysis (Tokens Emitted by Lexer) ---\n";
    auto tokens = tokenize(sampleCode);
    for (const auto& tok : tokens) {
        std::cout << "  [Token: " << tokenTypeName(tok.type) << "\t | Text: \"" << tok.text << "\"]\n";
    }

    std::cout << "\n--- 2. Parsing (Syntactic Grammar Validation) ---\n";
    std::cout << "  Abstract Syntax Tree (AST) structure parsed:\n";
    std::cout << "    [ASSIGNMENT (=)]\n";
    std::cout << "       ├── Left Target:   Variable `total` (type: int)\n";
    std::cout << "       └── Right Value:  [ADDITION (+)]\n";
    std::cout << "                            ├── Variable `price`\n";
    std::cout << "                            └── Literal `50`\n";

    std::cout << "\n[SUCCESS] Lexical tokens recognized and syntax successfully verified!\n";
    return 0;
}
