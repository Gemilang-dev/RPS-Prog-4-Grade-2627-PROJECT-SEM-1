#pragma once
#include "turnstile_cpu.h"
#include "passenger_queue.h"
#include "refund_stack.h"

class TurnstileController {
private:
    TurnstileCPU cpu;
    PassengerQueue queue;
    RefundStack refundStack;
    int baseFareCents;
public:
    TurnstileController(int baseFare);
    void addPassenger(const Passenger& p);
    void processAllPassengers();
    void rollbackLastTransaction();
};
