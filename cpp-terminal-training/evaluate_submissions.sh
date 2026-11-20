#!/usr/bin/env bash
# ==============================================================================
# evaluate_submissions.sh - Batch Assessment Review for Instructors
# ==============================================================================
# Inspects one or multiple student answers.json files in a directory and
# produces a formative comprehension summary for teachers.
# ==============================================================================

GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
RESET='\033[0m'
BOLD='\033[1m'

TARGET="${1:-submissions}"

echo -e "${CYAN}================================================================${RESET}"
echo -e "${BOLD}${BLUE}  📋 BATCH EVALUATION: C++ TERMINAL & COMMENTS TRAINING${RESET}"
echo -e "${CYAN}================================================================${RESET}"
echo -e "${MAGENTA}Purpose: Formative overview of student cohort comprehension.${RESET}\n"

FILES=()
if [ -d "$TARGET" ]; then
    for f in "$TARGET"/*.json; do
        [ -e "$f" ] && FILES+=("$f")
    done
elif [ -f "$TARGET" ]; then
    FILES+=("$TARGET")
else
    echo -e "${YELLOW}[Warning] Target '$TARGET' not found.${RESET}"
    echo -e "Usage:"
    echo -e "  ${BOLD}./evaluate_submissions.sh submissions/${RESET}     (evaluate directory of json submissions)"
    echo -e "  ${BOLD}./evaluate_submissions.sh answers.json${RESET}         (evaluate single json file)"
    exit 1
fi

TOTAL_FILES=${#FILES[@]}
if [ "$TOTAL_FILES" -eq 0 ]; then
    echo -e "${YELLOW}No .json files found in '$TARGET'.${RESET}"
    exit 0
fi

echo -e "Found ${BOLD}${TOTAL_FILES}${RESET} submission(s) to evaluate.\n"

for f in "${FILES[@]}"; do
    echo -e "${BLUE}Evaluating:${RESET} $f"
    ./verify_answers.sh "$f"
done
