#ifndef REGISTERS_H
#define REGISTERS_H

#include <cstdint>

namespace MimicBoy {
    struct Registers {
      private:
        std::uint8_t A = 0;
        std::uint8_t B = 0;
        std::uint8_t C = 0;
        std::uint8_t D = 0;
        std::uint8_t E = 0;
        std::uint8_t H = 0;
        std::uint8_t L = 0;
        std::uint8_t F = 0;

      public:
        std::uint8_t getA() const { return A; }
        std::uint8_t getB() const { return B; }
        std::uint8_t getC() const { return C; }
        std::uint8_t getD() const { return D; }
        std::uint8_t getE() const { return E; }
        std::uint8_t getH() const { return H; }
        std::uint8_t getL() const { return L; }
        std::uint8_t getF() const { return F; }

        std::uint16_t getAF() const { return (A << 8) | F; }
        std::uint16_t getBC() const { return (B << 8) | C; }
        std::uint16_t getDE() const { return (D << 8) | E; }
        std::uint16_t getHL() const { return (H << 8) | L; }

        void setA(std::uint8_t value) { A = value; }
        void setB(std::uint8_t value) { B = value; }
        void setC(std::uint8_t value) { C = value; }
        void setD(std::uint8_t value) { D = value; }
        void setE(std::uint8_t value) { E = value; }
        void setH(std::uint8_t value) { H = value; }
        void setL(std::uint8_t value) { L = value; }
        void setF(std::uint8_t value) { F = value; }

        void setAF(std::uint16_t value) {  A = value >> 8; F = value & 0xFF;  }
        void setBC(std::uint16_t value) {  B = value >> 8; C = value & 0xFF;  }
        void setDE(std::uint16_t value) {  D = value >> 8; E = value & 0xFF;  }
        void setHL(std::uint16_t value) {  H = value >> 8; L = value & 0xFF;  }
    };
}

#endif //REGISTERS_H
