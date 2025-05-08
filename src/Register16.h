#ifndef REGISTER16_H
#define REGISTER16_H

#include "Register8.h"

namespace MimicBoy {
    class Register16 {
    private:
        Register8 high;
        Register8 low;

    public:
        Register16() = default;

        Register16(uint16_t value) { set(value); }

        Register16 &operator=(uint16_t value) {
            set(value);
            return *this;
        }

        uint16_t get() const {
            return (high.get() << 8) | low.get();
        }

        void set(uint16_t value) {
            high.set((value >> 8) & 0xFF);
            low.set(value & 0xFF);
        }

        Register8 &getHigh() { return high; }
        Register8 &getLow() { return low; }
    };
}

#endif //REGISTER16_H
