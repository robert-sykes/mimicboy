#include "CPU.h"

namespace MimicBoy {
    CPU::CPU(Memory& memory) : memory(memory) {
        this->opcodesMap = std::unordered_map<uint16_t, std::function<void()>>{
            {0x00, [this] { nop(); }},

            // LD r8,r8 instructions
            // B as destination (0x40-0x45)
            {0x40, [this] { ldr8r8(getB(), getB()); }},
            {0x41, [this] { ldr8r8(getB(), getC()); }},
            {0x42, [this] { ldr8r8(getB(), getD()); }},
            {0x43, [this] { ldr8r8(getB(), getE()); }},
            {0x44, [this] { ldr8r8(getB(), getH()); }},
            {0x45, [this] { ldr8r8(getB(), getL()); }},

            // C as destination (0x48-0x4D)
            {0x48, [this] { ldr8r8(getC(), getB()); }},
            {0x49, [this] { ldr8r8(getC(), getC()); }},
            {0x4A, [this] { ldr8r8(getC(), getD()); }},
            {0x4B, [this] { ldr8r8(getC(), getE()); }},
            {0x4C, [this] { ldr8r8(getC(), getH()); }},
            {0x4D, [this] { ldr8r8(getC(), getL()); }},

            // D as destination (0x50-0x55)
            {0x50, [this] { ldr8r8(getD(), getB()); }},
            {0x51, [this] { ldr8r8(getD(), getC()); }},
            {0x52, [this] { ldr8r8(getD(), getD()); }},
            {0x53, [this] { ldr8r8(getD(), getE()); }},
            {0x54, [this] { ldr8r8(getD(), getH()); }},
            {0x55, [this] { ldr8r8(getD(), getL()); }},

            // E as destination (0x58-0x5D)
            {0x58, [this] { ldr8r8(getE(), getB()); }},
            {0x59, [this] { ldr8r8(getE(), getC()); }},
            {0x5A, [this] { ldr8r8(getE(), getD()); }},
            {0x5B, [this] { ldr8r8(getE(), getE()); }},
            {0x5C, [this] { ldr8r8(getE(), getH()); }},
            {0x5D, [this] { ldr8r8(getE(), getL()); }},

            // H as destination (0x60-0x65)
            {0x60, [this] { ldr8r8(getH(), getB()); }},
            {0x61, [this] { ldr8r8(getH(), getC()); }},
            {0x62, [this] { ldr8r8(getH(), getD()); }},
            {0x63, [this] { ldr8r8(getH(), getE()); }},
            {0x64, [this] { ldr8r8(getH(), getH()); }},
            {0x65, [this] { ldr8r8(getH(), getL()); }},

            // L as destination (0x68-0x6D)
            {0x68, [this] { ldr8r8(getL(), getB()); }},
            {0x69, [this] { ldr8r8(getL(), getC()); }},
            {0x6A, [this] { ldr8r8(getL(), getD()); }},
            {0x6B, [this] { ldr8r8(getL(), getE()); }},
            {0x6C, [this] { ldr8r8(getL(), getH()); }},
            {0x6D, [this] { ldr8r8(getL(), getL()); }},

            // A as destination (0x78-0x7D)
            {0x78, [this] { ldr8r8(getA(), getB()); }},
            {0x79, [this] { ldr8r8(getA(), getC()); }},
            {0x7A, [this] { ldr8r8(getA(), getD()); }},
            {0x7B, [this] { ldr8r8(getA(), getE()); }},
            {0x7C, [this] { ldr8r8(getA(), getH()); }},
            {0x7D, [this] { ldr8r8(getA(), getL()); }},
        };
    }

    void CPU::execute() {
        uint8_t opcode = this->memory.read(this->PC);

        if (this->opcodesMap.contains(opcode)) {
            this->opcodesMap[opcode]();
        } else {
            throw InvalidOpcodeException();
        }
    }

    void CPU::nop() {
        ++this->PC;
    }
}
