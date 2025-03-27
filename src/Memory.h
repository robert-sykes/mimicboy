#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include <cstdint>

namespace MimicBoy {
    /**
     * @class Memory
     * @brief Represents a memory management system with fixed size.
     *
     * This class provides an abstraction for a memory module, offering
     * storage and initialization for a pre-defined size of memory.
     */
    class Memory {
    private:
        /**
         * @var MemorySize
         * @brief Represents the size of the memory in bytes.
         *
         * This constant defines the fixed size of the memory module, calculated
         * as 0x10000 bytes (65,536), which can be used for allocation or memory-related operations.
         */
        static constexpr size_t MemorySize = 0x10000; // 64KB
        /**
         * @variable memory
         * @brief An array representing the memory storage of fixed size.
         *
         * This variable serves as a storage container for the memory system,
         * initialized to zero, with a size defined by the constant MemorySize.
         */
        std::array<uint8_t, MemorySize> memory = {};
    public:
        Memory() = default; /**
         * Default constructor for the Memory class.
         *
         * @return A default-initialized instance of the Memory class.
         */
    };
}

#endif //MEMORY_H
