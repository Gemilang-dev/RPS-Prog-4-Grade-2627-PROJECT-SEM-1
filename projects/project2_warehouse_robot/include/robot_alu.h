#pragma once
#include "parcel_types.h"

// Virtual Robot Microcode ALU Processor (NO inline assembly)
struct RobotALU {
    int AX = 0; // Register AX: Parcel Weight (grams)
    int BX = 0; // Register BX: Maximum Robot Arm Capacity (grams)
    int CX = 0; // Register CX: Speed / Priority Factor (1, 2, 3)
    int DX = 0; // Register DX: Computed Shipping Energy / Tariff
    bool OverloadFlag = false;
    bool MatchFlag = false;

    void MOV_AX(int weight);
    void MOV_BX(int maxCapacity);
    void MOV_CX(int priorityFactor);
    void MUL_CX(int factor);
    void COMPUTE_ENERGY();
    void CMP_WEIGHT();
    bool JLE_ACCEPT();
    bool JG_REJECT();
    bool JLE_DISPATCH();
    bool JG_DIVERT();
};
