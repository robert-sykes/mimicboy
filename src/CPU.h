#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <functional>
#include <unordered_map>
#include "Register16.h"
#include "Register8.h"
#include "CPUFlag.h"
#include "Memory.h"

namespace MimicBoy {
    class CPU {
    private:
        Register16 PC{0x0000};
        Register16 SP{0xFFFE};
        Register8 A{0x00}, B{0x00}, C{0x00}, D{0x00}, E{0x00}, H{0x00}, L{0x00}, F{0x00};
        Register16 AF{0x0000}, BC{0x0000}, DE{0x0000}, HL{0x0000};

        CPUFlag flag;

        Memory& memory;

        std::unordered_map<uint16_t, std::function<void()>> opcodesMap;
    public:
        explicit CPU(Memory& memory);

        CPUFlag& getFlag() { return flag; }

        void setAF(const uint16_t val) { AF.set(val); }
        void setBC(const uint16_t val) { BC.set(val); }
        void setDE(const uint16_t val) { DE.set(val); }
        void setHL(const uint16_t val) { HL.set(val); }

        void setPC(const uint16_t val) { PC.set(val); }
        void setSP(const uint16_t val) { SP.set(val); }

        void setA(const uint8_t val) { A.set(val); }
        void setB(const uint8_t val) { B.set(val); }
        void setC(const uint8_t val) { C.set(val); }
        void setD(const uint8_t val) { D.set(val); }
        void setE(const uint8_t val) { E.set(val); }
        void setH(const uint8_t val) { H.set(val); }
        void setL(const uint8_t val) { L.set(val); }
        void setF(const uint8_t val) { F.set(val); }

        void execute();
    private:
        void nop();

        void ldr8r8(Register8 &left, Register8 &right);
    };
}

#endif //CPU_H
