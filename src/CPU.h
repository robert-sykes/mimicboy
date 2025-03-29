#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include "Registers.h"
#include "CPUFlag.h"

namespace MimicBoy {
    class CPU {
    private:
        uint16_t PC = 0x0000;
        uint16_t SP = 0xFFFE;

        Registers registers;
        CPUFlag flag;
    public:
        CPU() = default;

        Registers& getRegisters() { return registers; }
        CPUFlag& getFlag() { return flag; }
    };
}

#endif //CPU_H
