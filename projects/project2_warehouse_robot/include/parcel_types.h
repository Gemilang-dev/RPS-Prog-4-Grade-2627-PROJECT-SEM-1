#pragma once
#include <string>

enum class PriorityLevel {
    STANDARD = 1,
    EXPRESS = 2,
    OVERNIGHT = 3
};

enum class RoutingBay {
    BAY_LOCAL,
    BAY_AIR_EXPRESS,
    REJECT_CHUTE
};

struct Parcel {
    std::string trackingId;
    int weightGrams = 0;
    PriorityLevel priority = PriorityLevel::STANDARD;
    std::string barcode;
    std::string description;

    Parcel() = default;
    Parcel(std::string id, int w, PriorityLevel p)
        : trackingId(id), weightGrams(w), priority(p), barcode(id) {}
    Parcel(std::string id, int w, std::string desc)
        : trackingId(id), weightGrams(w), priority(PriorityLevel::STANDARD), barcode(id), description(desc) {}
};

struct PalletManifest {
    std::string palletId;
    int totalWeightGrams = 0;
    int totalItems = 0;
};
