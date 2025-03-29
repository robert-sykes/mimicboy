#include <gtest/gtest.h>
#include "src/Memory.h"

TEST(MemoryTest, ReadWrite) {
    MimicBoy::Memory memory;

    memory.write(0x1234, 0xAB);
    EXPECT_EQ(memory.read(0x1234), 0xAB);
}