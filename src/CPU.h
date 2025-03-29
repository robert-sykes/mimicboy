#ifndef CPU_H
#define CPU_H

#include <cstdint>

namespace MimicBoy {
    class CPU {
    private:
        uint16_t PC = 0x0000;
        uint16_t SP = 0xFFFE;
    public:
        CPU() = default;
    };
}

#endif //CPU_H
