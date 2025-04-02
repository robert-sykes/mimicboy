#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

#include "Register8.h"

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
        static constexpr size_t MemorySize = 0xFFFF; // 64KB
        /**
         * @variable memory
         * @brief An array representing the memory storage of fixed size.
         *
         * This variable serves as a storage container for the memory system,
         * initialized to zero, with a size defined by the constant MemorySize.
         */
        std::array<uint8_t, MemorySize> memory = {};

    public:
        Memory() = default;

        /**
         * @brief Reads a byte from the memory at the specified address.
         *
         * This method retrieves the value stored at the given memory address.
         *
         * @param address The memory address to read from. Must be within the valid range.
         * @return The byte value stored at the specified memory address.
         */
         [[nodiscard]] uint8_t read(const uint16_t address) const {
            return memory[address];
         }

        /**
         * @brief Writes a value to a specific memory address.
         *
         * This method stores a given value at the specified address in memory.
         *
         * @param address The memory address to write to.
         * @param value The value to store at the specified address.
         *
         */
        void write(const uint16_t address, const uint8_t value) {
            memory[address] = value;
        }

        void load(const std::initializer_list<std::pair<uint16_t, uint8_t> > &data) {
            for (const auto &[address, value]: data) {
                if (address >= MemorySize) {
                    throw std::out_of_range("Address exceeds available memory.");
                }
                memory[address] = value; // Example: load value into the specified address
            }
        }
    };
}

#endif //MEMORY_H
