#pragma once
#include <queue>
#include "types.h"

class PassengerQueue {
private:
    std::queue<Passenger> line;
public:
    void enqueue(const Passenger& p);
    Passenger dequeue();
    void enqueuePassenger(const Passenger& p) { enqueue(p); }
    Passenger dequeuePassenger() { return dequeue(); }
    bool isEmpty() const;
    size_t count() const;
};
