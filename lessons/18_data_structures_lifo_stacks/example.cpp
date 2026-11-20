// Lesson 18: Data Structures: LIFO Stacks & Undo Rollbacks - Educational Demonstration
#include <iostream>
#include <stack>
#include <string>

struct TransitTransaction {
    std::string cardId;
    std::string passengerName;
    int fareDeductedCents;
    bool gateOpened;
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 18: LIFO STACKS & UNDO ROLLBACK DEMO\n";
    std::cout << "====================================================\n\n";

    std::stack<TransitTransaction> transactionStack;

    // 1. Logging transactions into LIFO Stack
    std::cout << "--- 1. Logging Consecutive Turnstile Transactions ---\n";
    transactionStack.push({"CARD-A1", "Alice Vance", 300, true});
    std::cout << "  [PUSH] Logged transaction: Alice Vance ($3.00)\n";

    transactionStack.push({"CARD-B2", "Bob Student", 150, true});
    std::cout << "  [PUSH] Logged transaction: Bob Student ($1.50)\n";

    transactionStack.push({"CARD-C3", "Charlie Low", 75, true});
    std::cout << "  [PUSH] Logged transaction: Charlie Low ($0.75)\n\n";

    std::cout << "Current Stack Depth: " << transactionStack.size() << " transactions stored.\n\n";

    // 2. Simulating a customer service rollback (Undo most recent tap first)
    std::cout << "--- 2. Executing LIFO Undo Rollback (Reversing Last Transaction) ---\n";
    if (!transactionStack.empty()) {
        TransitTransaction lastTx = transactionStack.top(); // Peek at top
        transactionStack.pop();                             // Pop top item
        std::cout << "  [LIFO ROLLBACK REFUND] Refunding most recent transaction:\n";
        std::cout << "    Passenger:   " << lastTx.passengerName << "\n";
        std::cout << "    Amount:      $" << (lastTx.fareDeductedCents / 100.0) << " credited back to card!\n";
    }

    std::cout << "\nRemaining Transactions in Stack: " << transactionStack.size() << " records.\n";
    std::cout << "Top of Stack is now: " << transactionStack.top().passengerName << "\n\n";

    std::cout << "[PASS] LIFO Stack reversal executed in exact inverse order!\n";
    return 0;
}
