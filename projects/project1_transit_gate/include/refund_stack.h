#pragma once
#include <stack>
#include "types.h"

class RefundStack {
private:
    std::stack<TransactionRecord> history;
public:
    void pushRecord(const TransactionRecord& rec);
    TransactionRecord popRollback();
    void pushTransaction(const TransactionRecord& rec) { pushRecord(rec); }
    TransactionRecord popTransaction() { return popRollback(); }
    bool hasRecords() const;
    size_t historyCount() const;
};
