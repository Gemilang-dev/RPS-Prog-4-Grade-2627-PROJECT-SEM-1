#include "action_stack.h"

void ActionStack::recordTreatment(const MedicalTreatment& treat) {
    treatments.push(treat);
}

MedicalTreatment ActionStack::rollbackLast() {
    if (treatments.empty()) return {"", "", "", 0};
    MedicalTreatment topItem = treatments.top();
    treatments.pop();
    return topItem;
}

bool ActionStack::hasHistory() const {
    return !treatments.empty();
}

size_t ActionStack::count() const {
    return treatments.size();
}
