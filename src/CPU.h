#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <functional>
#include <unordered_map>
#include "CPUFlag.h"
#include "Memory.h"
#include "exceptions/InvalidOpcodeException.h"

namespace MimicBoy {
    class CPU {
    private:
        std::uint16_t PC{0x0000};
        std::uint16_t SP{0xFFFE};
        std::uint16_t AF{0x0000}, BC{0x0000}, DE{0x0000}, HL{0x0000};

        CPUFlag flag;
        Memory& memory;

        std::unordered_map<uint16_t, std::function<void()>> opcodesMap;
    public:
        explicit CPU(Memory& memory);

        CPUFlag& getFlag() { return flag; }

        [[nodiscard]] std::uint16_t getPC() const { return PC; }
        [[nodiscard]] std::uint16_t getSP() const { return SP; }

        [[nodiscard]] std::uint16_t getAF() const { return AF; }
        [[nodiscard]] std::uint16_t getBC() const { return BC; }
        [[nodiscard]] std::uint16_t getDE() const { return DE; }
        [[nodiscard]] std::uint16_t getHL() const { return HL; }

        std::uint8_t getA() const { return AF & 0xFF; }
        std::uint8_t getB() const { return BC & 0xFF; }
        std::uint8_t getC() const { return DE & 0xFF; }
        std::uint8_t getD() const { return HL & 0xFF; }
        std::uint8_t getE() const { return (AF >> 8) & 0xFF; }
        std::uint8_t getF() const { return (BC >> 8) & 0xFF; }
        std::uint8_t getH() const { return (DE >> 8) & 0xFF; }
        std::uint8_t getL() const { return (HL >> 8) & 0xFF; }

        void setAF(const std::uint16_t val) { AF = val; }
        void setBC(const std::uint16_t val) { BC = val; }
        void setDE(const std::uint16_t val) { DE = val; }
        void setHL(const std::uint16_t val) { HL = val; }
        void setPC(const std::uint16_t val) { PC = val; }
        void setSP(const std::uint16_t val) { SP = val; }

        void setA(const std::uint8_t val) { AF = (AF & 0xFF00) | val; }
        void setB(const std::uint8_t val) { BC = (BC & 0xFF00) | val; }
        void setC(const std::uint8_t val) { DE = (DE & 0xFF00) | val; }
        void setD(const std::uint8_t val) { HL = (HL & 0xFF00) | val; }
        void setE(const std::uint8_t val) { AF = (AF & 0x00FF) | (val << 8); }
        void setF(const std::uint8_t val) { BC = (BC & 0x00FF) | (val << 8); }
        void setH(const std::uint8_t val) { DE = (DE & 0x00FF) | (val << 8); }
        void setL(const std::uint8_t val) { HL = (HL & 0x00FF) | (val << 8); }

        void execute();
    private:
        void nop();

        void ldr8r8(std::uint8_t left, std::uint8_t right);

        void ldr8r16(std::uint8_t left, std::uint8_t right);
    };
}

#endif //CPU_H
