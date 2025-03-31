#ifndef REGISTER16_H
#define REGISTER16_H

#include <cstdint>

namespace MimicBoy {
    class Register16 {
    private:
        uint16_t value;

    public:
        Register16() : value(0x0000) {
        }

        explicit Register16(const uint16_t val) : value(val) {
        }

        [[nodiscard]] uint16_t get() const { return value; }
        [[nodiscard]] uint8_t getLow() const { return value & 0xFF; }
        [[nodiscard]] uint8_t getHigh() const { return (value >> 8) & 0xFF; }

        void set(const uint16_t val) { this->value = val; }
        void setLow(const uint8_t val) { this->value = (this->value & 0xFF00) | val; }
        void setHigh(const uint8_t val) { this->value = (this->value & 0x00FF) | (val << 8); }

        Register16 &operator++() {
            ++value;
            return *this;
        }

        Register16 operator++(int) {
            Register16 temp = *this;
            ++value;
            return temp;
        }
    };
}

#endif //REGISTER16_H
