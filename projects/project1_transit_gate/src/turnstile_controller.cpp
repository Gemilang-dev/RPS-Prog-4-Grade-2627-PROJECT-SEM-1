#include <iostream>
#include "turnstile_controller.h"

TurnstileController::TurnstileController(int baseFare) : baseFareCents(baseFare) {}

void TurnstileController::addPassenger(const Passenger& p) {
    queue.enqueue(p);
}

void TurnstileController::processAllPassengers() {
    std::cout << "--- Processing Transit Turnstile Passenger Line (FIFO) ---\n";
    while (!queue.isEmpty()) {
        Passenger p = queue.dequeue();
        std::cout << "Commuter: " << p.name << " (" << p.id << ") | Initial Balance: $" << p.balanceCents / 100.0 << "\n";

        // Load into CPU registers
        cpu.MOV_AX(p.balanceCents);
        cpu.MOV_BX(baseFareCents);

        // Apply discount factor based on tier
        int tierDivisor = (p.tier == TicketTier::STUDENT) ? 2 : ((p.tier == TicketTier::SENIOR) ? 4 : 1);
        cpu.MOV_CX(tierDivisor);
        cpu.COMPUTE_FARE();
        cpu.CMP_BALANCE_FARE();

        if (cpu.JGE_OPEN()) {
            cpu.SUB_BALANCE();
            std::cout << "  -> [GATE OPEN] Deducted fare: $" << cpu.DX / 100.0 << " | Remaining Balance: $" << cpu.AX / 100.0 << "\n";
            refundStack.pushRecord({p.id, p.name, cpu.DX, 12345678});
        } else if (cpu.JL_DENY()) {
            std::cout << "  -> [GATE LOCKED] Required: $" << cpu.DX / 100.0 << ", Has: $" << cpu.AX / 100.0 << " (Insufficient!)\n";
        }
    }
}

void TurnstileController::rollbackLastTransaction() {
    if (refundStack.hasRecords()) {
        TransactionRecord rec = refundStack.popRollback();
        std::cout << "\n[LIFO ROLLBACK REFUND] Refunding commuter: " << rec.passengerName << " ($" << rec.fareDeducted / 100.0 << " returned)\n";
    }
}
