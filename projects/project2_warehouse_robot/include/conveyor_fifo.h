#pragma once
#include <queue>
#include "parcel_types.h"

class ConveyorFIFO {
private:
    std::queue<Parcel> belt;
public:
    void placeParcel(const Parcel& p);
    Parcel advanceBelt();
    void receiveParcel(const Parcel& p) { placeParcel(p); }
    Parcel pickNextParcel() { return advanceBelt(); }
    bool hasParcels() const;
    size_t queueLength() const;
};
