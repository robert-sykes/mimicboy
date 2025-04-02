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

TEST(CPUTest, ExecuteLDR8R8) {
    MimicBoy::Memory memory;
    memory.load({
        {0x0000, 0x41},
    });

    MimicBoy::CPU cpu(memory);
    cpu.setC(1);

    cpu.execute();

    ASSERT_EQ(cpu.getB(), 1);
    ASSERT_EQ(cpu.getPC(), 0x0001);
}

TEST(CPUTest, ExecuteLDR8R16) {
    MimicBoy::Memory memory;
    memory.load({
        {0x0000, 0x46},
        {0x0001, 20}
    });

    MimicBoy::CPU cpu(memory);
    cpu.setHL(0x0001);

    cpu.execute();

    ASSERT_EQ(cpu.getB(), 20);
    ASSERT_EQ(cpu.getPC(), 0x0001);
}
