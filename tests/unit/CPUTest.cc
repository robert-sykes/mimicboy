#include <gtest/gtest.h>
#include "src/CPU.h"

TEST(CpuTest, InvalidOpcode) {
    MimicBoy::Memory memory;
    MimicBoy::CPU cpu(memory);

    memory.write(0x0000, 0xFF);

    ASSERT_THROW(cpu.execute(), InvalidOpcodeException);
}

TEST(CPUTest, ExecuteNOP) {
    MimicBoy::Memory memory;
    MimicBoy::CPU cpu(memory);

    memory.write(0x0000, 0x00);
    cpu.execute();

    ASSERT_EQ(cpu.getPC(), 0x0001);
}