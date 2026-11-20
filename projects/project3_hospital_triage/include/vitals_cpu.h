#pragma once
#include "patient_types.h"

// Medical Diagnostic Microcode Processor (NO inline assembly)
struct VitalsCPU {
    int AX = 0; // Register AX: Patient Heart Rate (BPM)
    int BX = 0; // Register BX: Cardiac Emergency Threshold (e.g. 130 BPM)
    int CX = 0; // Register CX: Oxygen Saturation %
    int DX = 0; // Register DX: Computed Clinical Severity Score
    bool DangerFlag = false;
    bool HypoxiaFlag = false;

    void MOV_AX(int heartRate);
    void MOV_BX(int threshold);
    void MOV_CX(int o2Sat);
    void COMPUTE_SEVERITY();
    void CMP_VITALS();
    bool JG_CRITICAL();
    bool JLE_STABLE();
};
