#pragma once
#include <stack>
#include "patient_types.h"

class ActionStack {
private:
    std::stack<MedicalTreatment> treatments;
public:
    void recordTreatment(const MedicalTreatment& treat);
    MedicalTreatment rollbackLast();
    bool hasHistory() const;
    size_t count() const;
};
