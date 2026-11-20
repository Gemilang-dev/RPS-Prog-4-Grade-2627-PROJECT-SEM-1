#pragma once
#include <queue>
#include "patient_types.h"

class ERQueue {
private:
    std::queue<Patient> line;
public:
    void registerArrival(const Patient& p);
    Patient admitNext();
    bool hasPatients() const;
    size_t count() const;
};
