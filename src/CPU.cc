#include "CPU.h"

namespace MimicBoy {
    CPU::CPU(Memory& memory) : memory(memory) {
        this->opcodesMap = std::unordered_map<uint16_t, std::function<void()>>{
            {0x00, [this] { nop(); }},

            // LD R8, R8
            {0x40, [this] { ldr8r8(this->getB(), this->getB()); }},
            {0x41, [this] { ldr8r8(this->getB(), this->getC()); }},
            {0x42, [this] { ldr8r8(this->getB(), this->getD()); }},
            {0x43, [this] { ldr8r8(this->getB(), this->getE()); }},
            {0x44, [this] { ldr8r8(this->getB(), this->getH()); }},
            {0x45, [this] { ldr8r8(this->getB(), this->getL()); }},
            {0x46, [this] { ldr8r16(this->getB(), this->HL); }},
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
