#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <functional>
#include <unordered_map>
#include "Register.h"
#include "CPUFlag.h"
#include "Memory.h"

namespace MimicBoy {
    class CPU {
    private:
        Register<uint8_t> PC{0x0000};
        uint16_t SP = 0xFFFE;
        Register<uint8_t> A{0x00}, B{0x00}, C{0x00}, D{0x00}, E{0x00}, H{0x00}, L{0x00}, F{0x00};

        CPUFlag flag;
        Memory& memory;

        std::unordered_map<uint16_t, std::function<void()>> opcodesMap;
    public:
        explicit CPU(Memory& memory);

        CPUFlag& getFlag() { return flag; }

        void execute();
    private:
        void nop();
    };
}

#endif //CPU_H
