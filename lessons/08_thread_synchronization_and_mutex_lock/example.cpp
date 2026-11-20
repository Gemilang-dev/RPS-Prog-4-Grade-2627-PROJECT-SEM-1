// Lesson 08: Thread Synchronization & Mutex Lock - Educational Demonstration
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex printMutex;
std::mutex bankMutex;
int sharedBankVault = 0;

void depositMoney(int customerId, int amount) {
    // Protect shared bank account with a mutex lock
    {
        std::lock_guard<std::mutex> lock(bankMutex);
        sharedBankVault += amount;
    }

    // Protect console output from overlapping jumbled characters
    {
        std::lock_guard<std::mutex> printLock(printMutex);
        std::cout << "  [Deposit Verified] Customer #" << customerId 
                  << " added $" << amount 
                  << " \t| Current Vault: $" << sharedBankVault << "\n";
    }
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 08: THREAD SYNCHRONIZATION & MUTEX DEMO\n";
    std::cout << "====================================================\n\n";

    std::cout << "--- 10 Concurrent Customers Depositing Simultaneously ---\n";
    std::vector<std::thread> threadPool;
    for (int i = 1; i <= 10; ++i) {
        threadPool.emplace_back(depositMoney, i, 50);
    }

    for (auto& worker : threadPool) {
        worker.join();
    }

    std::cout << "\n--- Final Audit Report ---\n";
    std::cout << "  Expected Vault Balance: $500\n";
    std::cout << "  Actual Vault Balance:   $" << sharedBankVault << "\n\n";

    if (sharedBankVault == 500) {
        std::cout << "[PASS] Mutex synchronization succeeded! Zero race conditions.\n";
        return 0;
    } else {
        std::cout << "[FAIL] Race condition detected!\n";
        return 1;
    }
}
