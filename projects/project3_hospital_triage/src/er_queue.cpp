#include "er_queue.h"

void ERQueue::registerArrival(const Patient& p) {
    line.push(p);
}

Patient ERQueue::admitNext() {
    if (line.empty()) return {"", "", 0, {0, 0, 0}};
    Patient p = line.front();
    line.pop();
    return p;
}

bool ERQueue::hasPatients() const {
    return !line.empty();
}

size_t ERQueue::count() const {
    return line.size();
}
