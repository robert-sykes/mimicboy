#include "CPU.h"

namespace MimicBoy {
    void CPU::ldr8r8(Register8 &left, Register8 &right) {
        left.set(right.get());
        ++this->PC;
    }

    void CPU::ldr8r16(Register8 &left, Register16 &right) {
         left.set(this->memory.read(right.get()));
         ++this->PC;
    }
}