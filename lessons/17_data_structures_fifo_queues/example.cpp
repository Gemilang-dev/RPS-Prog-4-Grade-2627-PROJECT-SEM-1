// Lesson 17: Data Structures: FIFO Queues - Educational Demonstration
#include <iostream>
#include <queue>
#include <string>

struct Commuter {
    std::string id;
    std::string name;
    int cardBalanceCents;
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 17: FIFO QUEUES (FIRST-IN, FIRST-OUT) DEMO\n";
    std::cout << "====================================================\n\n";

    std::queue<Commuter> stationLine;

    // 1. Enqueue commuters as they step into the turnstile lane
    std::cout << "--- 1. Enqueueing Commuters at Station Entry Lane ---\n";
    stationLine.push({"C-101", "Alice Vance", 600});
    std::cout << "  [ENQUEUE] Station Lane: Alice Vance joined the line.\n";

    stationLine.push({"C-102", "Bob Student", 300});
    std::cout << "  [ENQUEUE] Station Lane: Bob Student joined the line.\n";

    stationLine.push({"C-103", "Charlie Low", 150});
    std::cout << "  [ENQUEUE] Station Lane: Charlie Low joined the line.\n";

    stationLine.push({"C-104", "Dorothy Senior", 450});
    std::cout << "  [ENQUEUE] Station Lane: Dorothy Senior joined the line.\n\n";

    std::cout << "Current Queue Depth: " << stationLine.size() << " commuters in line.\n\n";

    // 2. Dequeue commuters as they tap cards at the turnstile gate
    std::cout << "--- 2. Dequeueing Commuters Through Turnstile Gate (FIFO Order) ---\n";
    int serveOrder = 1;
    while (!stationLine.empty()) {
        Commuter c = stationLine.front(); // Peek at front of line
        stationLine.pop();               // Dequeue from front
        std::cout << "  [" << serveOrder++ << "] Scanned Card: " << c.id 
                  << " (" << c.name << ") | Balance: $" << (c.cardBalanceCents / 100.0) << "\n";
    }

    std::cout << "\n[PASS] All commuters served in strict chronological FIFO order!\n";
    return 0;
}
