#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <functional>
#include <unordered_map>
#include "CPUFlag.h"
#include "Memory.h"
#include "Register16.h"
#include "exceptions/InvalidOpcodeException.h"

namespace MimicBoy {
    class CPU {
    private:
        std::uint16_t PC{0x0000};
        std::uint16_t SP{0xFFFE};
        Register16 AF{0x0000}, BC{0x0000}, DE{0x0000}, HL{0x0000};

        CPUFlag flag;
        Memory& memory;

        std::unordered_map<uint16_t, std::function<void()>> opcodesMap;
    public:
        explicit CPU(Memory& memory);

        CPUFlag& getFlag() { return flag; }

        [[nodiscard]] std::uint16_t getPC() const { return PC; }
        [[nodiscard]] std::uint16_t getSP() const { return SP; }

        [[nodiscard]] Register16 getAF() const { return AF; }
        [[nodiscard]] Register16 getBC() const { return BC; }
        [[nodiscard]] Register16 getDE() const { return DE; }
        [[nodiscard]] Register16 getHL() const { return HL; }

        Register8 &getA() { return AF.getHigh(); }
        Register8 &getF() { return AF.getLow(); }
        Register8 &getB() { return BC.getHigh(); }
        Register8 &getC() { return BC.getLow(); }
        Register8 &getD() { return DE.getHigh(); }
        Register8 &getE() { return DE.getLow(); }
        Register8 &getH() { return HL.getHigh(); }
        Register8 &getL() { return HL.getLow(); }

        void execute();
    private:
        void nop();

        void ldr8r8(Register8 &dest, Register8 &src);

        void ldr8r16(std::uint8_t left, std::uint8_t right);
    };
}

#endif //CPU_H
