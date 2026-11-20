#pragma once
#include <string>

enum class TriageLevel {
    CODE_RED = 1,    // Critical emergency (ICU)
    CODE_YELLOW = 2, // Urgent observation
    CODE_GREEN = 3   // Stable ambulatory
};

struct VitalSigns {
    int heartRateBpm;
    int systolicBP;
    int oxygenSaturation;
};

struct Patient {
    std::string id;
    std::string name;
    int age;
    VitalSigns vitals;
};

struct MedicalTreatment {
    std::string patientId;
    std::string patientName;
    std::string drugName;
    int dosageUnits;
};
