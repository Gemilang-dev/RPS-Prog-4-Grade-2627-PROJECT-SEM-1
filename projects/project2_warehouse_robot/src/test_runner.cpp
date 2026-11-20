#include <iostream>
#include <cassert>
#include "robot_alu.h"
#include "conveyor_fifo.h"
#include "pallet_lifo.h"

int main() {
    std::cout << "\n========================================\n";
    std::cout << "  TEAM 2: AUTOMATED LOCAL TEST SUITE\n";
    std::cout << "========================================\n\n";

    int passed = 0;
    int total = 5;

    // Test 1: Register Move & Multiplier
    {
        RobotALU alu;
        alu.MOV_AX(1500);
        alu.MOV_BX(2000);
        alu.MUL_CX(4);
        if (alu.AX == 1500 && alu.BX == 2000 && alu.CX == 4) {
            std::cout << "[PASS] Test 1: Register MOV_AX, MOV_BX, and MUL_CX.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 1: Register loading or multiplication error.\n";
        }
    }

    // Test 2: Weight Comparison & Overload Flag
    {
        RobotALU alu;
        alu.MOV_AX(2500);
        alu.MOV_BX(2000);
        alu.CMP_WEIGHT();
        bool overOk = (alu.OverloadFlag == true);

        alu.MOV_AX(1200);
        alu.CMP_WEIGHT();
        bool safeOk = (alu.OverloadFlag == false);

        if (overOk && safeOk) {
            std::cout << "[PASS] Test 2: CMP_WEIGHT evaluates OverloadFlag (AX > BX).\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 2: OverloadFlag logic error. Expected true when AX > BX.\n";
        }
    }

    // Test 3: Branching JLE_DISPATCH & JG_DIVERT
    {
        RobotALU alu;
        alu.MOV_AX(1800);
        alu.MOV_BX(2000);
        alu.CMP_WEIGHT();
        bool dispatchOk = alu.JLE_DISPATCH();

        alu.MOV_AX(3200);
        alu.CMP_WEIGHT();
        bool divertOk = alu.JG_DIVERT();

        if (dispatchOk && divertOk) {
            std::cout << "[PASS] Test 3: Branching JLE_DISPATCH and JG_DIVERT.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 3: Branching error. JLE should accept when weight <= limit; JG should divert.\n";
        }
    }

    // Test 4: Conveyor FIFO Order
    {
        ConveyorFIFO belt;
        belt.receiveParcel({"P1", 800, "Books"});
        belt.receiveParcel({"P2", 1500, "Electronics"});
        bool fifoOk = (belt.pickNextParcel().barcode == "P1") && (belt.pickNextParcel().barcode == "P2");
        if (fifoOk) {
            std::cout << "[PASS] Test 4: Conveyor FIFO preserves intake arrival order.\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 4: Conveyor FIFO failed to return parcels in first-in first-out order.\n";
        }
    }

    // Test 5: Pallet LIFO Order
    {
        PalletLIFO pallet;
        pallet.stackParcel({"P1", 800, "Books"});
        pallet.stackParcel({"P2", 1500, "Electronics"});
        bool lifoOk = (pallet.unstackParcel().barcode == "P2") && (pallet.unstackParcel().barcode == "P1");
        if (lifoOk) {
            std::cout << "[PASS] Test 5: Pallet LIFO unloads from top (last-in first-out).\n";
            passed++;
        } else {
            std::cout << "[FAIL] Test 5: Pallet LIFO failed to unload top parcel first.\n";
        }
    }

    std::cout << "\n----------------------------------------\n";
    std::cout << "  RESULT: " << passed << " / " << total << " Tests Passed\n";
    if (passed == total) {
        std::cout << "  CONGRATULATIONS! ALL TESTS PASSED! 🎉\n";
    } else {
        std::cout << "  Review the failed tests and check clues in src/robot_alu.cpp.\n";
    }
    std::cout << "========================================\n\n";

    return (passed == total) ? 0 : 1;
}
