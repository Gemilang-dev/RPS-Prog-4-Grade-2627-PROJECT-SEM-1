#include "refund_stack.h"

void RefundStack::pushRecord(const TransactionRecord& rec) {
    history.push(rec);
}

TransactionRecord RefundStack::popRollback() {
    if (history.empty()) return {"", "", 0, 0};
    TransactionRecord topRec = history.top();
    history.pop();
    return topRec;
}

bool RefundStack::hasRecords() const {
    return !history.empty();
}

size_t RefundStack::historyCount() const {
    return history.size();
}
