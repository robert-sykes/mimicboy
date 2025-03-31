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
        Register PC{0x0000};
        Register SP{0xFFFE};
        Register AF{0x0000}, BC{0x0000}, DE{0x0000}, HL{0x0000};

        CPUFlag flag;

        Memory& memory;

        std::unordered_map<uint16_t, std::function<void()>> opcodesMap;
    public:
        explicit CPU(Memory& memory);

        CPUFlag& getFlag() { return flag; }

        void execute();
    private:
        void nop();

        void ld(Register &left, Register &right);
    };
}

#endif //CPU_H
