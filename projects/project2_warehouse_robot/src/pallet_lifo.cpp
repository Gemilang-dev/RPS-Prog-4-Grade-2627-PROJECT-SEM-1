#include "pallet_lifo.h"

bool PalletLIFO::pushParcel(const Parcel& p, int maxPalletWeight) {
    if (totalWeightGrams + p.weightGrams > maxPalletWeight) {
        return false; // Pallet capacity exceeded
    }
    stack.push(p);
    totalWeightGrams += p.weightGrams;
    return true;
}

Parcel PalletLIFO::popTopParcel() {
    if (stack.empty()) return {"", 0, PriorityLevel::STANDARD};
    Parcel topP = stack.top();
    stack.pop();
    totalWeightGrams -= topP.weightGrams;
    return topP;
}

bool PalletLIFO::isEmpty() const {
    return stack.empty();
}

int PalletLIFO::getTotalWeight() const {
    return totalWeightGrams;
}

size_t PalletLIFO::itemCount() const {
    return stack.size();
}
