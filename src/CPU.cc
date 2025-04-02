#include "CPU.h"


namespace MimicBoy {
    CPU::CPU(Memory& memory) : memory(memory) {
        this->opcodesMap = std::unordered_map<uint16_t, std::function<void()>>{
            {0x00, [this] { nop(); }},

            // LD R8, R8
            {0x40, [this] { ldr8r8(this->B, this->B); }},
            {0x41, [this] { ldr8r8(this->B, this->C); }},
            {0x42, [this] { ldr8r8(this->B, this->D); }},
            {0x43, [this] { ldr8r8(this->B, this->E); }},
            {0x44, [this] { ldr8r8(this->B, this->H); }},
            {0x45, [this] { ldr8r8(this->B, this->L); }},
            {0x46, [this] { ldr8r16(this->B, this->HL); }},
        };
    }

    void CPU::execute() {
        uint8_t opcode = this->memory.read(this->PC.get());

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