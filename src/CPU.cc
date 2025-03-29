#include "CPU.h"

namespace MimicBoy {
    CPU::CPU(Memory& memory) : memory(memory) {
        this->opcodesMap = std::unordered_map<uint16_t, std::function<void()>>{
            {0x00, std::bind(&CPU::nop, this)}
        };
    }

    void CPU::execute() {
        uint8_t opcode = this->memory.read(this->PC);

        if (this->opcodesMap.find(opcode) != this->opcodesMap.end()) {
             this->opcodesMap[opcode]();
        } else {
             throw std::runtime_error("Invalid opcode");
        }
    }

    void CPU::nop() {
        this->PC++;
    }
}