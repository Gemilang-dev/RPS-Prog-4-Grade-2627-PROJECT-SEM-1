#pragma once
#include "vitals_cpu.h"
#include "er_queue.h"
#include "action_stack.h"

class TriageController {
private:
    VitalsCPU cpu;
    ERQueue queue;
    ActionStack stack;
    int bpmThreshold;
public:
    TriageController(int thresholdBpm);
    void admitIncomingPatient(const Patient& p);
    void evaluateAllWaitingPatients();
    void rollbackEmergencyAction();
};
