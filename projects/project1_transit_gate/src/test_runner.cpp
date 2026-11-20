#include <iostream>
#include <cassert>
#include "turnstile_cpu.h"
#include "passenger_queue.h"
#include "refund_stack.h"

int main() {
    std::cout << "\n========================================\n";
    std::cout << "  TEAM 1: AUTOMATED LOCAL TEST SUITE\n";
    std::cout << "========================================\n\n";

    int passed = 0;
    int total = 5;

    // Test 1: Register Move & Accumulator
    {
        TurnstileCPU cpu;
        cpu.MOV_AX(500);
        cpu.MOV_BX(250);
        if (cpu.AX == 500 && cpu.BX == 250) {
            std::cout << "[PASS] Test 1: Register MOV_AX and MOV_BX loaded correctly.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 1: Register values incorrect. Expected AX=500, BX=250. Got AX=" 
                      << cpu.AX << ", BX=" << cpu.BX << "\n";
        }
    }

    // Test 2: Arithmetic Add & Sub
    {
        TurnstileCPU cpu;
        cpu.MOV_AX(300);
        cpu.ADD_AX(200);
        cpu.SUB_AX(150);
        if (cpu.AX == 350) {
            std::cout << "[PASS] Test 2: ADD_AX and SUB_AX arithmetic operations.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 2: Arithmetic error. Expected AX=350, got AX=" << cpu.AX << "\n";
        }
    }

    // Test 3: Comparison Flags
    {
        TurnstileCPU cpu;
        cpu.MOV_AX(100);
        cpu.MOV_BX(250);
        cpu.CMP_AX_BX();
        bool flagOk = (cpu.SignFlag == true && cpu.ZeroFlag == false);
        
        cpu.MOV_AX(250);
        cpu.CMP_AX_BX();
        flagOk = flagOk && (cpu.ZeroFlag == true && cpu.SignFlag == false);

        if (flagOk) {
            std::cout << "[PASS] Test 3: CMP_AX_BX evaluated ZeroFlag and SignFlag.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 3: CMP flags error. Check SignFlag (AX < BX) and ZeroFlag (AX == BX).\n";
        }
    }

    // Test 4: Branching Instructions JGE & JL
    {
        TurnstileCPU cpu;
        cpu.MOV_AX(500);
        cpu.MOV_BX(250);
        cpu.CMP_AX_BX();
        bool openOk = cpu.JGE_OPEN() && (cpu.CX == 1);

        cpu.MOV_AX(100);
        cpu.CMP_AX_BX();
        bool denyOk = cpu.JL_DENY() && (cpu.CX == 0);

        if (openOk && denyOk) {
            std::cout << "[PASS] Test 4: Branching JGE_OPEN (CX=1) and JL_DENY (CX=0).\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 4: Branching error. JGE must set CX=1 when balance >= fare; JL must set CX=0 when balance < fare.\n";
        }
    }

    // Test 5: FIFO Queue & LIFO Stack Integrity
    {
        PassengerQueue q;
        q.enqueuePassenger({"C1", "Alice", 500});
        q.enqueuePassenger({"C2", "Bob", 150});
        bool fifoOk = (q.dequeuePassenger().name == "Alice") && (q.dequeuePassenger().name == "Bob");

        RefundStack s;
        s.pushTransaction({"C1", "Alice", 250, true});
        s.pushTransaction({"C2", "Bob", 0, false});
        bool lifoOk = (s.popTransaction().passengerName == "Bob") && (s.popTransaction().passengerName == "Alice");

        if (fifoOk && lifoOk) {
            std::cout << "[PASS] Test 5: FIFO Passenger Queue and LIFO Refund Stack order.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 5: Data structure error. Verify queue push/pop and stack push/pop.\n";
        }
    }

    std::cout << "\n----------------------------------------\n";
    std::cout << "  RESULT: " << passed << " / " << total << " Tests Passed\n";
    if (passed == total) {
        std::cout << "  CONGRATULATIONS! ALL TESTS PASSED! 🎉\n";
    } else {
        std::cout << "  Review the failed tests and check clues in src/turnstile_cpu.cpp.\n";
    }
    std::cout << "========================================\n\n";

    return (passed == total) ? 0 : 1;
}
