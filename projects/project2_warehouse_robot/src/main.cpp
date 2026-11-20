#include <iostream>
#include "dispatcher_controller.h"

int main() {
    std::cout << "========================================================\n";
    std::cout << "   WAREHOUSE ROBOT & PARCEL DISPATCHER - PROJECT 2\n";
    std::cout << "   Architecture: 8 Modular C++ Files (ALU, FIFO, LIFO)\n";
    std::cout << "========================================================\n\n";

    DispatcherController dispatcher(2500); // 2500 grams maximum arm payload

    // Parcels arriving on conveyor
    dispatcher.incomingConveyorParcel({"PKG-201", 1200, PriorityLevel::STANDARD});
    dispatcher.incomingConveyorParcel({"PKG-202", 3400, PriorityLevel::EXPRESS});  // Overweight! (Limit 2500g)
    dispatcher.incomingConveyorParcel({"PKG-203", 850, PriorityLevel::OVERNIGHT}); // Overnight high-speed
    dispatcher.incomingConveyorParcel({"PKG-204", 2100, PriorityLevel::STANDARD});

    dispatcher.processConveyorFeed();

    // Emergency pallet unload test
    dispatcher.emergencyUnloadTopParcel();

    std::cout << "\nProject 2 execution completed successfully!\n";
    return 0;
}
