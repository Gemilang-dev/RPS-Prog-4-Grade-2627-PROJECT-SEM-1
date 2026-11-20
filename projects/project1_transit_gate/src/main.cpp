#include <iostream>
#include "turnstile_controller.h"

int main() {
    std::cout << "========================================================\n";
    std::cout << "   SMART TRANSIT TURNSTILE CONTROLLER - PROJECT 1\n";
    std::cout << "   Architecture: 8 Modular C++ Files (CPU, FIFO, LIFO)\n";
    std::cout << "========================================================\n\n";

    TurnstileController gate(300); // Base fare: $3.00 (300 cents)

    // Add diverse commuters (Standard, Student, Senior)
    gate.addPassenger({"P101", "Alice Vance", 600, TicketTier::STANDARD});
    gate.addPassenger({"P102", "Bob Student", 200, TicketTier::STUDENT}); // $1.50 fare, has $2.00 -> OK!
    gate.addPassenger({"P103", "Charlie Low", 100, TicketTier::STANDARD}); // $3.00 fare, has $1.00 -> DENIED!
    gate.addPassenger({"P104", "Dorothy Senior", 150, TicketTier::SENIOR}); // $0.75 fare, has $1.50 -> OK!

    gate.processAllPassengers();

    // Trigger LIFO refund rollback
    gate.rollbackLastTransaction();

    std::cout << "\nProject 1 execution completed successfully!\n";
    return 0;
}
