#include "CPU.h"

namespace MimicBoy {
    void CPU::ldr8r8(Register8 &left, Register8 &right) {
        left.set(right.get());
    }
}