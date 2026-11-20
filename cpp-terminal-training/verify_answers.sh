#!/usr/bin/env bash
# ==============================================================================
# verify_answers.sh - Self-Assessment Verification Script (C++ Terminal & Comments)
# ==============================================================================
# Formative learning feedback script (NO PENALTY / NO GRADES).
# Analyzes student answers.json and outputs feedback in terminal.
# ==============================================================================

GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
RESET='\033[0m'
BOLD='\033[1m'

echo -e "${CYAN}================================================================${RESET}"
echo -e "${BOLD}${BLUE}  🌱 CONCEPT VERIFICATION: C++ TERMINAL & COMMENTS${RESET}"
echo -e "${CYAN}================================================================${RESET}"
echo -e "${MAGENTA}Note: This tool checks conceptual understanding (Zero Pressure, No Grades).${RESET}\n"

ANSWERS_FILE="${1:-answers.json}"

if [ ! -f "$ANSWERS_FILE" ]; then
    if [ "$1" == "--interactive" ]; then
        echo -e "${YELLOW}Interactive Mode: Answer directly in your terminal.${RESET}\n"
        read -p "Student Name: " studentName
        read -p "1. Command to compile program.cpp into an app: " compileCmd
        read -p "2. Command to run app on Linux/macOS: " runCmd
        read -p "3. g++ flag for all warnings: " warningFlag
        read -p "4. Flag for C++17 standard: " stdFlag
        read -p "5. Difference between // and /* */: " commentDiff
        read -p "6. Can block comments be nested?: " nestedComm
        read -p "7. Preprocessor role on comments: " prepRole
        read -p "8. Chaining command with &&: " chainCmd
        read -p "9. Example function doc comment: " docComm
    else
        echo -e "${YELLOW}[Info] File '${ANSWERS_FILE}' not found in current folder.${RESET}"
        echo -e "Open ${BOLD}student_questions.html${RESET} in any browser, complete the questions,"
        echo -e "click ${BOLD}'Download answers.json'${RESET}, and save it in this directory."
        echo -e "\nOr launch interactive terminal mode now:"
        echo -e "  ${BOLD}./verify_answers.sh --interactive${RESET}\n"
        exit 0
    fi
else
    echo -e "${BLUE}Reading answers from file:${RESET} ${BOLD}${ANSWERS_FILE}${RESET}\n"
    read_field() {
        python3 -c "import json; d=json.load(open('$ANSWERS_FILE')); print(d.get('$1',''))" 2>/dev/null
    }
    studentName=$(read_field "studentName")
    compileCmd=$(read_field "compileCmd")
    runCmd=$(read_field "runCmd")
    warningFlag=$(read_field "warningFlag")
    stdFlag=$(read_field "stdFlag")
    commentDiff=$(read_field "commentDifference")
    nestedComm=$(read_field "nestedComments")
    prepRole=$(read_field "preprocessorRole")
    chainCmd=$(read_field "chainedCmd")
    docComm=$(read_field "docCommentExample")
fi

echo -e "Learner: ${BOLD}${studentName:-Self-Learner}${RESET}\n"
echo -e "${CYAN}---------------- Checkpoint Evaluation ----------------${RESET}"

score=0

# Q1
if [[ "$compileCmd" == *"g++"* ]] && [[ "$compileCmd" == *"-o"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q1: Terminal Compilation - Correct usage of g++ and -o flag."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q1: Terminal Compilation - Include g++ and -o flag (e.g., g++ program.cpp -o app)."
fi

# Q2
if [[ "$runCmd" == *"./"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q2: Program Execution - Accurately used relative path prefix ./."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q2: Program Execution - Use ./ to execute local binaries in Unix shells."
fi

# Q3
if [[ "$warningFlag" == *"-Wall"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q3: Compiler Flags - Identified -Wall for full standard warnings."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q3: Compiler Flags - Remember -Wall activates essential compiler warnings."
fi

# Q4
if [[ "${stdFlag,,}" == *"c++17"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q4: Language Standard - Modern C++17 flag correctly specified."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q4: Language Standard - Specify -std=c++17."
fi

# Q5
if [[ "$commentDiff" == *"//"* ]] && ([[ "$commentDiff" == *"/*"* ]] || [[ "$commentDiff" == *"*/"* ]]); then
    echo -e "[${GREEN}PASS${RESET}] Q5: Comment Delimiters - Clear distinction between single-line and block comments."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q5: Comment Delimiters - Distinguish // (single-line) and /* ... */ (block)."
fi

# Q6
if [[ "${nestedComm,,}" == *"no"* ]] || [[ "${nestedComm,,}" == *"cannot"* ]] || [[ "${nestedComm,,}" == *"error"* ]] || [[ "${nestedComm,,}" == *"tidak"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q6: Comment Nesting - Understood why block comments cannot nest in C++."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q6: Comment Nesting - In C++, the first */ closes the block comment, causing syntax errors."
fi

# Q7
if [[ "${prepRole,,}" == *"preprocessor"* ]] || [[ "${prepRole,,}" == *"strip"* ]] || [[ "${prepRole,,}" == *"hapus"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q7: Preprocessor Role - Correctly noted preprocessor strips comments before machine code emission."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q7: Preprocessor Role - Comments are removed during preprocessing and do not affect binary size."
fi

# Q8
if [[ "$chainCmd" == *"&&"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q8: Workflow Chaining - Good command chaining using &&."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q8: Workflow Chaining - Use && to ensure execution only runs if compilation succeeded."
fi

# Q9
if [[ "$docComm" == *"/**"* ]] || [[ "$docComm" == *"@"* ]]; then
    echo -e "[${GREEN}PASS${RESET}] Q9: Documentation Format - Neat Doxygen documentation styling."
    ((score++))
else
    echo -e "[${YELLOW}REVIEW${RESET}] Q9: Documentation Format - Practice using /** with @param and @return tags."
fi

echo -e "\n${CYAN}================================================================${RESET}"
echo -e "Mastery Summary: ${BOLD}${score}/9${RESET} checkpoints verified."
if [ "$score" -ge 8 ]; then
    echo -e "${GREEN}Outstanding! You are fully prepared to start the C++ Systems Curriculum!${RESET}"
else
    echo -e "${YELLOW}Great effort! Read terminal_cpp_guide.md to review any remaining items.${RESET}"
fi
echo -e "${CYAN}================================================================${RESET}\n"
