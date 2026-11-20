#include "conveyor_fifo.h"

void ConveyorFIFO::placeParcel(const Parcel& p) {
    belt.push(p);
}

Parcel ConveyorFIFO::advanceBelt() {
    if (belt.empty()) return {"", 0, PriorityLevel::STANDARD};
    Parcel p = belt.front();
    belt.pop();
    return p;
}

bool ConveyorFIFO::hasParcels() const {
    return !belt.empty();
}

size_t ConveyorFIFO::queueLength() const {
    return belt.size();
}
