// Lesson 12: Resolving Namespace Conflicts & Aliases - Educational Demonstration
#include <iostream>
#include <string>

namespace UndergroundSubwayLine {
    class FareCard {
    public:
        int balanceCents = 1500;
        void printDetails() {
            std::cout << "  [Subway Line] Metracard Balance: $" << (balanceCents / 100.0) << "\n";
        }
    };
}

namespace RegionalBulletTrain {
    class FareCard {
    public:
        int balanceCents = 7500;
        void printDetails() {
            std::cout << "  [Bullet Train] Express High-Speed Card: $" << (balanceCents / 100.0) << "\n";
        }
    };
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 12: RESOLVING NAMESPACE CONFLICTS DEMO\n";
    std::cout << "====================================================\n\n";

    std::cout << "--- 1. Using Short Namespace Aliases ---\n";
    // Define clean short aliases for long namespaces
    namespace Subway = UndergroundSubwayLine;
    namespace Bullet = RegionalBulletTrain;

    Subway::FareCard cityPass;
    Bullet::FareCard expressPass;

    cityPass.printDetails();
    expressPass.printDetails();

    std::cout << "\n--- 2. Selective Scoped Import ---\n";
    {
        using Subway::FareCard;
        FareCard localSubwayCard;
        std::cout << "  Inside scoped block: default FareCard refers to Subway Line ($" 
                  << (localSubwayCard.balanceCents / 100.0) << ")\n";
    }

    std::cout << "\n[PASS] Namespace ambiguity resolved cleanly without name collisions!\n";
    return 0;
}
