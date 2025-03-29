#ifndef FLAGS_H
#define FLAGS_H

namespace MimicBoy {
    enum class CPUFlag {
        Zero = 1 << 7,
        Subtract = 1 << 6,
        HalfCarry = 1 << 5,
        Carry = 1 << 4,
    };
}

#endif //FLAGS_H
