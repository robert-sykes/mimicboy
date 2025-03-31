#ifndef REGISTER8_H
#define REGISTER8_H

#include <cstdint>

namespace MimicBoy {
    class Register8 {
    private:
        uint8_t value;

    public:
        Register8() : value(0x00) {
        }

        explicit Register8(const uint8_t val) : value(val) {
        }

        [[nodiscard]] uint8_t get() const { return value; }

        void set(const uint8_t val) { this->value = val; }

        Register8 &operator++() {
            ++value;
            return *this;
        }

        Register8 operator++(int) {
            Register8 temp = *this;
            ++value;
            return temp;
        }
    };
}

#endif //REGISTER8_H
