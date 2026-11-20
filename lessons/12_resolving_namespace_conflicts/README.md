# Lesson 12: Resolving Namespace Conflicts & Aliases

Welcome to Lesson 12! In this lesson, you will learn how to handle name collisions when two libraries or modules define identically named classes or functions.

---

## 🧒 Kid-Friendly Analogy: Two Toy Bins with a "RaceCar" in Both!
Imagine you have two toy boxes in your playroom:
- **Box 1:** `HotWheelsBox` contains a toy called `RaceCar`.
- **Box 2:** `LegoBox` also contains a toy called `RaceCar`.

If you dump both boxes onto the living room rug at the same time:
```cpp
using namespace HotWheelsBox;
using namespace LegoBox;

RaceCar car; // ❌ COMPILER FREEZES: "Which RaceCar do you mean?!"
```
The compiler throws an error:  
❌ `error: reference to 'RaceCar' is ambiguous`!

### The Three Solutions:
1. **Explicit Full Name:**  
   `HotWheelsBox::RaceCar myCar;` (Clear, unambiguous).
2. **Namespace Aliases (Cute Nicknames):**  
   If the namespace has a long name like `NationalMetropolitanTransitAuthority`, give it a short nickname:  
   `namespace MTA = NationalMetropolitanTransitAuthority;`  
   `MTA::Turnstile myGate;`
3. **Selective Using Declarations:**  
   Instead of dumping the entire box, only pick out the one toy you need:  
   `using HotWheelsBox::RaceCar;`

---

## ⚙️ Under the Hood: Deep Technical Explanation

### 1. Syntax of Namespace Aliasing
```cpp
namespace Metro = CityInfrastructure::PublicTransit::MetroLine;

// Now you can cleanly use Metro instead of the long 4-layer namespace!
Metro::SignalTower tower;
```

### 2. Selective Import vs Broad Import
```cpp
// ❌ Dangerous (dumps hundreds of identifiers into the file)
using namespace std;

// ✅ Clean & Safe (imports only what you specifically use)
using std::string;
using std::vector;
```

---

## 💻 Practical Code Example (`example.cpp`)

```cpp
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
    std::cout << "Resolving Namespace Conflicts with Aliases...\n\n";

    // Create handy short aliases
    namespace Subway = UndergroundSubwayLine;
    namespace Bullet = RegionalBulletTrain;

    Subway::FareCard cityPass;
    Bullet::FareCard expressPass;

    cityPass.printDetails();
    expressPass.printDetails();

    return 0;
}
```

---

## 🚀 How to Run in CLion and Terminal

### In CLion:
1. Open `lessons/12_resolving_namespace_conflicts/example.cpp`.
2. Right click inside `example.cpp` and select **Run 'example.cpp'**.

### In Terminal:
```bash
cd lessons/12_resolving_namespace_conflicts
g++ -Wall -std=c++17 example.cpp -o example && ./example
```
Or run the automated verification script:
```bash
bash verify.sh
```

---

## 🎯 Hands-On Mini Challenge
In `example.cpp`, try adding `using namespace UndergroundSubwayLine;` and `using namespace RegionalBulletTrain;` above `main()`, then try instantiating `FareCard card;`. Observe the exact compiler ambiguity error! Then restore the aliases.
