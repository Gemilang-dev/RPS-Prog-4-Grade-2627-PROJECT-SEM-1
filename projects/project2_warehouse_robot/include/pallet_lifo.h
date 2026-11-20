#pragma once
#include <stack>
#include "parcel_types.h"

class PalletLIFO {
private:
    std::stack<Parcel> stack;
    int totalWeightGrams = 0;
public:
    bool pushParcel(const Parcel& p, int maxPalletWeight = 25000);
    Parcel popTopParcel();
    void stackParcel(const Parcel& p) { pushParcel(p); }
    Parcel unstackParcel() { return popTopParcel(); }
    bool isEmpty() const;
    int getTotalWeight() const;
    size_t itemCount() const;
    size_t parcelCount() const { return itemCount(); }
};
