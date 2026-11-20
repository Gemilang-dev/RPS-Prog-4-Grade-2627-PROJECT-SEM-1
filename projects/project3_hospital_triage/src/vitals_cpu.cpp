#include "vitals_cpu.h"

// ==============================================================================
// STUDENT ASSIGNMENT: Virtual Emergency Vitals CPU
// ==============================================================================
// Read each instruction carefully. Follow the CLUES and refer to the suggested
// lessons to implement each member function.
// ==============================================================================

// TODO 1: Copy heart rate (BPM) into register AX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions)
//       and Lesson 14 (Separating Declarations and Definitions).
void VitalsCPU::MOV_AX(int heartRate) {
    // Write your code here:

}

// TODO 2: Copy cardiac danger threshold into register BX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions).
void VitalsCPU::MOV_BX(int threshold) {
    // Write your code here:

}

// TODO 3: Copy oxygen saturation percentage (% O2) into register CX.
// CLUE: Review Lesson 19 (Assembly Fundamentals: Registers & Instructions).
void VitalsCPU::MOV_CX(int o2Sat) {
    // Write your code here:

}

// TODO 4: Compute clinical severity score into register DX.
// Formula: DX = (AX / 10) + (100 - CX)
// CLUE: Review Lesson 19 (Arithmetic Instructions).
void VitalsCPU::COMPUTE_SEVERITY() {
    // Write your code here:

}

// TODO 5: Compare heart rate with threshold and evaluate oxygen levels.
// Set DangerFlag = true if AX > BX (cardiac distress / tachycardia), otherwise false.
// Set HypoxiaFlag = true if CX < 92 (blood oxygen dangerously low), otherwise false.
// CLUE: Review Lesson 19 (Comparison & Condition Flags).
void VitalsCPU::CMP_VITALS() {
    // Write your code here:

}

// TODO 6: Branch if patient is in critical condition (Code Red).
// Return true if DangerFlag is true OR HypoxiaFlag is true, otherwise false.
// CLUE: Review Lesson 19 (Conditional Branching).
bool VitalsCPU::JG_CRITICAL() {
    // Write your code here:
    return false;
}

// TODO 7: Branch if patient is stable (Stable Green).
// Return true if neither DangerFlag nor HypoxiaFlag is set, otherwise false.
// CLUE: Review Lesson 19 (Conditional Branching).
bool VitalsCPU::JLE_STABLE() {
    // Write your code here:
    return false;
}
