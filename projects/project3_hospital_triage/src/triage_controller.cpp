#include <iostream>
#include "triage_controller.h"

TriageController::TriageController(int thresholdBpm) : bpmThreshold(thresholdBpm) {}

void TriageController::admitIncomingPatient(const Patient& p) {
    queue.registerArrival(p);
}

void TriageController::evaluateAllWaitingPatients() {
    std::cout << "--- Triage Examination for ER Waiting Line (FIFO) ---\n";
    while (queue.hasPatients()) {
        Patient p = queue.admitNext();
        std::cout << "Patient: " << p.name << " (Age " << p.age << ") | Vitals: " 
                  << p.vitals.heartRateBpm << " BPM, " << p.vitals.oxygenSaturation << "% O2\n";

        cpu.MOV_AX(p.vitals.heartRateBpm);
        cpu.MOV_BX(bpmThreshold);
        cpu.MOV_CX(p.vitals.oxygenSaturation);
        cpu.COMPUTE_SEVERITY();
        cpu.CMP_VITALS();

        if (cpu.JG_CRITICAL()) {
            std::cout << "  -> [CODE RED] Severity Score: " << cpu.DX 
                      << " | Immediate ICU transfer! Administering emergency stabilizer...\n";
            stack.recordTreatment({p.id, p.name, "Adenosine", 6});
        } else if (cpu.JLE_STABLE()) {
            std::cout << "  -> [STABLE GREEN] Severity Score: " << cpu.DX 
                      << " | Patient directed to general examination room.\n";
        }
    }
}

void TriageController::rollbackEmergencyAction() {
    if (stack.hasHistory()) {
        MedicalTreatment t = stack.rollbackLast();
        std::cout << "\n[LIFO ROLLBACK REVERSAL] Drug allergy detected! Reversing medication: " 
                  << t.drugName << " (" << t.dosageUnits << " units) for " << t.patientName << "\n";
    }
}
