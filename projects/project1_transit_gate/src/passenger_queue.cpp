#include "passenger_queue.h"

void PassengerQueue::enqueue(const Passenger& p) {
    line.push(p);
}

Passenger PassengerQueue::dequeue() {
    if (line.empty()) return {"", "", 0, TicketTier::STANDARD};
    Passenger p = line.front();
    line.pop();
    return p;
}

bool PassengerQueue::isEmpty() const {
    return line.empty();
}

size_t PassengerQueue::count() const {
    return line.size();
}
