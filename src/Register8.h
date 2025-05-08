#ifndef REGISTER8_H
#define REGISTER8_H

#include <cstdint>

namespace MimicBoy {
    class Register8 {
    private:
        std::uint8_t value{0};

    public:
        uint8_t get() const { return value; }
        void set(uint8_t newValue) { value = newValue; }
    };
}


#endif //REGISTER8_H
