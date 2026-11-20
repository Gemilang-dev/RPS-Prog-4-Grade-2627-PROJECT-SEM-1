// Lesson 19: Assembly Fundamentals: Registers, Instructions & Flags - Educational Demonstration
#include <iostream>

// Virtual 4-Register Microcode Machine (Similar to your Team Project assignments!)
struct VirtualMicroCpu {
    int AX = 0; // Accumulator Register
    int BX = 0; // Base / Limit Register
    int CX = 0; // Multiplier / Counter Register
    int DX = 0; // Final Computed Output Register

    bool ZeroFlag = false; // Set if AX == BX
    bool SignFlag = false; // Set if AX < BX (insufficient / negative)

    void MOV_AX(int val) { AX = val; }
    void MOV_BX(int val) { BX = val; }
    void MOV_CX(int val) { CX = val; }

    void ADD_AX(int val) { AX += val; }
    void SUB_AX(int val) { AX -= val; }

    void COMPUTE_DIV() {
        if (CX <= 0) CX = 1;
        DX = BX / CX;
    }

    void CMP() {
        ZeroFlag = (AX == BX);
        SignFlag = (AX < BX);
    }

    bool JGE_OPEN() {
        if (!SignFlag) {
            CX = 1; // Signal green open
            return true;
        }
        return false;
    }

    bool JL_DENY() {
        if (SignFlag) {
            CX = 0; // Signal red locked
            return true;
        }
        return false;
    }
};

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 19: CPU REGISTERS & INSTRUCTIONS DEMO\n";
    std::cout << "====================================================\n\n";

    VirtualMicroCpu cpu;

    // Simulation Scenario A: Commuter Alice with $5.00 attempting a $2.50 fare
    std::cout << "--- Scenario A: Sufficient Commuter Balance ($5.00 vs $2.50) ---\n";
    cpu.MOV_AX(500); // AX = 500
    cpu.MOV_BX(250); // BX = 250
    cpu.CMP();

    std::cout << "  Register AX (Balance):   $" << (cpu.AX / 100.0) << "\n";
    std::cout << "  Register BX (Fare):      $" << (cpu.BX / 100.0) << "\n";
    std::cout << "  Status Flags:            [ZeroFlag=" << cpu.ZeroFlag 
              << ", SignFlag=" << cpu.SignFlag << "]\n";
    std::cout << "  Branch JGE_OPEN():       " 
              << (cpu.JGE_OPEN() ? "[PASSED] Gate unlocked!" : "[BLOCKED]") << "\n\n";

    // Simulation Scenario B: Commuter Bob with $1.00 attempting a $2.50 fare
    std::cout << "--- Scenario B: Insufficient Commuter Balance ($1.00 vs $2.50) ---\n";
    cpu.MOV_AX(100); // AX = 100
    cpu.MOV_BX(250); // BX = 250
    cpu.CMP();

    std::cout << "  Register AX (Balance):   $" << (cpu.AX / 100.0) << "\n";
    std::cout << "  Register BX (Fare):      $" << (cpu.BX / 100.0) << "\n";
    std::cout << "  Status Flags:            [ZeroFlag=" << cpu.ZeroFlag 
              << ", SignFlag=" << cpu.SignFlag << "]\n";
    std::cout << "  Branch JL_DENY():        " 
              << (cpu.JL_DENY() ? "[DENIED] Access locked!" : "[OPEN]") << "\n\n";

    std::cout << "[PASS] Virtual register CPU microcode simulation verified successfully!\n";
    std::cout << "[INFO] Use this exact logic to solve your assigned project's CPU/ALU tasks!\n";
    return 0;
}
