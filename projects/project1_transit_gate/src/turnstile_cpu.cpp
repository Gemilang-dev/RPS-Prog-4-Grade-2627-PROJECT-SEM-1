#include "turnstile_cpu.h"

// ==============================================================================
// STUDENT ASSIGNMENT: Virtual Turnstile CPU Register Machine
// ==============================================================================
// Read each instruction carefully. Follow the CLUES and refer to the suggested
// lessons to implement each member function.
// ==============================================================================

// TODO 1: Load commuter balance into register AX.
// CLUE: Need help? Review Lesson 19 (Assembly Fundamentals: Registers & Instructions)
//       and Lesson 14 (Separating Declarations and Definitions).
void TurnstileCPU::MOV_AX(int balance) {
    // Write your code here:
    
}

// TODO 2: Load base fare into register BX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions).
void TurnstileCPU::MOV_BX(int baseFare) {
    // Write your code here:

}

// TODO 3: Load ticket tier divisor factor into register CX (e.g., 1 for Standard, 2 for Student).
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions).
void TurnstileCPU::MOV_CX(int divisor) {
    // Write your code here:

}

// TODO 4: Add value to register AX (Accumulator).
// CLUE: Review Lesson 19 (Assembly Fundamentals: Arithmetic Instructions).
void TurnstileCPU::ADD_AX(int val) {
    // Write your code here:

}

// TODO 5: Deduct value from register AX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Arithmetic Instructions).
void TurnstileCPU::SUB_AX(int val) {
    // Write your code here:

}

// TODO 6: Calculate final fare into register DX.
// Formula: DX = BX / CX (Base fare divided by discount factor).
// Guard: If CX <= 0, set CX = 1 to prevent division by zero!
// CLUE: Review Lesson 04 (Compiler Optimization) & Lesson 19.
void TurnstileCPU::COMPUTE_FARE() {
    // Write your code here:

}

// TODO 7: Deduct calculated fare (DX) from passenger balance (AX).
// Formula: AX = AX - DX.
// CLUE: Review Lesson 19.
void TurnstileCPU::SUB_BALANCE() {
    // Write your code here:

}

// TODO 8: Compare card balance (AX) with final fare (DX).
// Set ZeroFlag = true if AX == DX, otherwise false.
// Set SignFlag = true if AX < DX (insufficient balance!), otherwise false.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Comparison & Status Flags).
void TurnstileCPU::CMP_BALANCE_FARE() {
    // Write your code here:

}

// TODO 9: Compare register AX with register BX.
// Set ZeroFlag = true if AX == BX, otherwise false.
// Set SignFlag = true if AX < BX, otherwise false.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Comparison & Status Flags).
void TurnstileCPU::CMP_AX_BX() {
    // Write your code here:

}

// TODO 10: Jump if Greater or Equal (JGE) - Open Gate.
// If balance is sufficient (SignFlag is false / balance >= fare):
//   1. Set CX = 1 (Signal open)
//   2. Set GateReg = 1
//   3. Return true
// Otherwise return false.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Conditional Branching).
bool TurnstileCPU::JGE_OPEN() {
    // Write your code here:
    return false;
}

// TODO 11: Jump if Less (JL) - Deny Access.
// If balance is insufficient (SignFlag is true / balance < fare):
//   1. Set CX = 0 (Signal locked)
//   2. Set GateReg = 0
//   3. Return true
// Otherwise return false.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Conditional Branching).
bool TurnstileCPU::JL_DENY() {
    // Write your code here:
    return false;
}
