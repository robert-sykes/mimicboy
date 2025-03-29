#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <functional>
#include <unordered_map>
#include "Registers.h"
#include "CPUFlag.h"
#include "Memory.h"

namespace MimicBoy {
    class CPU {
    private:
        uint16_t PC = 0x0000;
        uint16_t SP = 0xFFFE;

        Registers registers;
        CPUFlag flag;
        Memory& memory;

        std::unordered_map<uint16_t, std::function<void()>> opcodesMap;
    public:
        explicit CPU(Memory& memory);

        Registers& getRegisters() { return registers; }
        CPUFlag& getFlag() { return flag; }
        
        void execute();
    private:
        void nop();
    };
}

#endif //CPU_H
