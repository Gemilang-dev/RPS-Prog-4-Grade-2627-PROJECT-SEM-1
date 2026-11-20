#include <iostream>
#include "dispatcher_controller.h"

DispatcherController::DispatcherController(int armLimitGrams) : maxArmCapacity(armLimitGrams) {}

void DispatcherController::incomingConveyorParcel(const Parcel& p) {
    conveyor.placeParcel(p);
}

void DispatcherController::processConveyorFeed() {
    std::cout << "--- Robot Sorting Incoming Conveyor Belt (FIFO) ---\n";
    while (conveyor.hasParcels()) {
        Parcel p = conveyor.advanceBelt();
        std::cout << "Sensor Scanned: " << p.trackingId << " | Weight: " << p.weightGrams << "g | Priority: " 
                  << static_cast<int>(p.priority) << "\n";

        alu.MOV_AX(p.weightGrams);
        alu.MOV_BX(maxArmCapacity);
        alu.MOV_CX(static_cast<int>(p.priority));
        alu.COMPUTE_ENERGY();
        alu.CMP_WEIGHT();

        if (alu.JLE_ACCEPT()) {
            std::cout << "  -> [ACCEPTED] Energy Units: " << alu.DX << " | Stacking on dispatch pallet (LIFO)...\n";
            pallet.pushParcel(p);
        } else if (alu.JG_REJECT()) {
            std::cout << "  -> [REJECTED OVERWEIGHT] Weight " << alu.AX << "g exceeds arm limit " << alu.BX << "g! Diverting to heavy bay.\n";
        }
    }
}

void DispatcherController::emergencyUnloadTopParcel() {
    if (!pallet.isEmpty()) {
        Parcel topP = pallet.popTopParcel();
        std::cout << "\n[LIFO PALLET UNLOAD] Unstacking top parcel from wooden pallet: " << topP.trackingId << " (" << topP.weightGrams << "g)\n";
    }
}
