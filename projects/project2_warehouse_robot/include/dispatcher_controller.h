#pragma once
#include "robot_alu.h"
#include "conveyor_fifo.h"
#include "pallet_lifo.h"

class DispatcherController {
private:
    RobotALU alu;
    ConveyorFIFO conveyor;
    PalletLIFO pallet;
    int maxArmCapacity;
public:
    DispatcherController(int armLimitGrams);
    void incomingConveyorParcel(const Parcel& p);
    void processConveyorFeed();
    void emergencyUnloadTopParcel();
};
