#pragma once
#include <string>

enum class TicketTier {
    STANDARD,
    STUDENT, // 50% discount
    SENIOR   // 75% discount
};

enum class GateState {
    LOCKED,
    UNLOCKED,
    ALARM
};

struct Passenger {
    std::string id;
    std::string name;
    int balanceCents;
    TicketTier tier = TicketTier::STANDARD;
};

struct TransactionRecord {
    std::string passengerId;
    std::string passengerName;
    int fareDeducted = 0;
    long timestamp = 0;
    bool approved = true;
};
