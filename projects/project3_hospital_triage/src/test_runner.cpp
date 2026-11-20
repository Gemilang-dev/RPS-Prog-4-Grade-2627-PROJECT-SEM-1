#include <iostream>
#include <cassert>
#include "vitals_cpu.h"
#include "er_queue.h"
#include "action_stack.h"

int main() {
    std::cout << "\n========================================\n";
    std::cout << "  TEAM 3: AUTOMATED LOCAL TEST SUITE\n";
    std::cout << "========================================\n\n";

    int passed = 0;
    int total = 5;

    // Test 1: Register Move & Clinical Severity Calculation
    {
        VitalsCPU cpu;
        cpu.MOV_AX(140);
        cpu.MOV_BX(130);
        cpu.MOV_CX(90);
        cpu.COMPUTE_SEVERITY();
        // Severity = (140/10) + (100 - 90) = 14 + 10 = 24
        if (cpu.AX == 140 && cpu.BX == 130 && cpu.CX == 90 && cpu.DX == 24) {
            std::cout << "[PASS] Test 1: Register MOV instructions and COMPUTE_SEVERITY calculation.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 1: Register assignment or DX score mismatch. Expected DX=24, got " << cpu.DX << "\n";
        }
    }

    // Test 2: Physiological CMP & Danger/Hypoxia Flags
    {
        VitalsCPU cpu;
        cpu.MOV_AX(145);
        cpu.MOV_BX(130);
        cpu.MOV_CX(98);
        cpu.CMP_VITALS();
        bool tachOk = (cpu.DangerFlag == true && cpu.HypoxiaFlag == false);

        cpu.MOV_AX(80);
        cpu.MOV_CX(88);
        cpu.CMP_VITALS();
        bool hypOk = (cpu.DangerFlag == false && cpu.HypoxiaFlag == true);

        if (tachOk && hypOk) {
            std::cout << "[PASS] Test 2: CMP_VITALS accurately detects DangerFlag and HypoxiaFlag.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 2: Flag evaluation error. Check DangerFlag (AX > BX) and HypoxiaFlag (CX < 92).\n";
        }
    }

    // Test 3: Triage Branching JG_CRITICAL & JLE_STABLE
    {
        VitalsCPU cpu;
        cpu.MOV_AX(150);
        cpu.MOV_BX(130);
        cpu.MOV_CX(95);
        cpu.CMP_VITALS();
        bool critOk = cpu.JG_CRITICAL();

        cpu.MOV_AX(75);
        cpu.MOV_CX(99);
        cpu.CMP_VITALS();
        bool stableOk = cpu.JLE_STABLE();

        if (critOk && stableOk) {
            std::cout << "[PASS] Test 3: Branching JG_CRITICAL and JLE_STABLE.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 3: Urgency branching error. Code Red should trigger on danger or hypoxia.\n";
        }
    }

    // Test 4: ER Intake FIFO Queue Order
    {
        ERQueue queue;
        queue.registerArrival({"P1", "Diana", 45, {145, 130, 96}});
        queue.registerArrival({"P2", "Eric", 28, {70, 110, 99}});
        bool fifoOk = (queue.admitNext().name == "Diana") && (queue.admitNext().name == "Eric");
        if (fifoOk) {
            std::cout << "[PASS] Test 4: ER Intake FIFO Queue order preserved.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 4: Patient arrival line failed to admit first-come first-served.\n";
        }
    }

    // Test 5: Medical Treatment LIFO Rollback
    {
        ActionStack stack;
        stack.recordTreatment({"P1", "Diana", "Epinephrine", 1});
        stack.recordTreatment({"P2", "Eric", "Aspirin", 2});
        bool lifoOk = (stack.rollbackLast().drugName == "Aspirin") && (stack.rollbackLast().drugName == "Epinephrine");
        if (lifoOk) {
            std::cout << "[PASS] Test 5: Emergency Action Stack rollback operates in LIFO order.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 5: Medication rollback did not reverse most recent drug first.\n";
        }
    }

    std::cout << "\n----------------------------------------\n";
    std::cout << "  RESULT: " << passed << " / " << total << " Tests Passed\n";
    if (passed == total) {
        std::cout << "  CONGRATULATIONS! ALL TESTS PASSED! 🎉\n";
    } else {
        std::cout << "  Review the failed tests and check clues in src/vitals_cpu.cpp.\n";
    }
    std::cout << "========================================\n\n";

    return (passed == total) ? 0 : 1;
}
