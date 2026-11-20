#include "robot_alu.h"

// ==============================================================================
// STUDENT ASSIGNMENT: Virtual Robot ALU Microcode Processor
// ==============================================================================
// Read each instruction carefully. Follow the CLUES and refer to the suggested
// lessons to implement each member function.
// ==============================================================================

// TODO 1: Store incoming parcel weight in register AX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions)
//       and Lesson 14 (Separating Declarations and Definitions).
void RobotALU::MOV_AX(int weight) {
    // Write your code here:

}

// TODO 2: Store robot arm payload limit in register BX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions).
void RobotALU::MOV_BX(int maxCapacity) {
    // Write your code here:

}

// TODO 3: Store priority multiplier (1 for Standard, 2 for Express, 3 for Overnight) in CX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions).
void RobotALU::MOV_CX(int priorityFactor) {
    // Write your code here:

}

// TODO 4: Multiply register CX by factor.
// If CX is 0, initialize it to 1 first, then multiply by factor.
// CLUE: Review Lesson 19 (Arithmetic Instructions).
void RobotALU::MUL_CX(int factor) {
    // Write your code here:

}

// TODO 5: Multiply weight (AX) by priority factor (CX) and store in DX.
// Formula: DX = AX * CX
// CLUE: Review Lesson 19 (Arithmetic Instructions).
void RobotALU::COMPUTE_ENERGY() {
    // Write your code here:

}

// TODO 6: Compare parcel weight (AX) with maximum arm limit (BX).
// Set MatchFlag = true if AX == BX, otherwise false.
// Set OverloadFlag = true if AX > BX (overweight!), otherwise false.
// CLUE: Review Lesson 19 (Comparison & Condition Flags).
void RobotALU::CMP_WEIGHT() {
    // Write your code here:

}

// TODO 7: Branch if weight is within capacity (Jump if Less or Equal - JLE).
// Return true if NOT overloaded (!OverloadFlag / weight <= limit), otherwise false.
// CLUE: Review Lesson 19 (Conditional Branching).
bool RobotALU::JLE_ACCEPT() {
    // Write your code here:
    return false;
}

// TODO 8: Branch if weight exceeds capacity (Jump if Greater - JG).
// Return true if OverloadFlag is true (weight > limit), otherwise false.
// CLUE: Review Lesson 19 (Conditional Branching).
bool RobotALU::JG_REJECT() {
    // Write your code here:
    return false;
}

bool RobotALU::JLE_DISPATCH() {
    return JLE_ACCEPT();
}

bool RobotALU::JG_DIVERT() {
    return JG_REJECT();
}
