#include "CPU.h"

namespace MimicBoy {
    void CPU::ldr8r8(Register8 &dest, Register8 &src) {
        dest.set(src.get());
        ++this->PC;
    }

    void CPU::ldr8r16(std::uint8_t left, std::uint8_t right) {
         left = memory.read(right);
         ++this->PC;
    }
}