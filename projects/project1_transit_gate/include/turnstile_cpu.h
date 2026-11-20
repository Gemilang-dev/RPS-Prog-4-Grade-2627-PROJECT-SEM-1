#pragma once
#include "types.h"

// Virtual Register Microcode Processor (NO inline assembly)
struct TurnstileCPU {
    int AX = 0; // Register AX: Card Balance (Cents)
    int BX = 0; // Register BX: Base Fare (Cents)
    int CX = 0; // Register CX: Discount Factor / Branch Flag (1 = OPEN, 0 = LOCKED)
    int DX = 0; // Register DX: Final Calculated Fare (Cents)
    int GateReg = 0; // 1 = OPEN, 0 = LOCKED

    bool ZeroFlag = false;
    bool SignFlag = false;

    void MOV_AX(int balance);
    void MOV_BX(int baseFare);
    void MOV_CX(int divisor);
    void ADD_AX(int val);
    void SUB_AX(int val);
    void COMPUTE_FARE();
    void SUB_BALANCE();
    void CMP_BALANCE_FARE();
    void CMP_AX_BX();
    bool JGE_OPEN();
    bool JL_DENY();
};
