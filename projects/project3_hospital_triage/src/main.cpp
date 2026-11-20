#include <iostream>
#include "triage_controller.h"

int main() {
    std::cout << "========================================================\n";
    std::cout << "   HOSPITAL EMERGENCY TRIAGE MONITOR - PROJECT 3\n";
    std::cout << "   Architecture: 8 Modular C++ Files (CPU, FIFO, LIFO)\n";
    std::cout << "========================================================\n\n";

    TriageController triage(130); // 130 BPM critical tachycardia threshold

    // Register patients arriving at intake
    triage.admitIncomingPatient({"PT-301", "Diana Prince", 45, {145, 135, 96}}); // High BPM -> CODE RED
    triage.admitIncomingPatient({"PT-302", "Eric Miller", 28, {74, 115, 99}});   // Normal -> STABLE GREEN
    triage.admitIncomingPatient({"PT-303", "Fiona Gallagher", 62, {110, 140, 89}}); // Hypoxia (89%) -> CODE RED

    triage.evaluateAllWaitingPatients();

    // Allergy alarm triggers LIFO reversal
    triage.rollbackEmergencyAction();

    std::cout << "\nProject 3 execution completed successfully!\n";
    return 0;
}
