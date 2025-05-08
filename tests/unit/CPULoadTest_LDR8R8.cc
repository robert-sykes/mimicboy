#include <gtest/gtest.h>
#include <src/CPU.h>

namespace MimicBoy::Test {
    TEST(CPUTest, ExecuteLDR8R8_BB) {
        Memory memory;
        memory.load({
            {0x0000, 0x40},
        });

        CPU cpu(memory);
        cpu.getB().set(10);

        cpu.execute();

        ASSERT_EQ(cpu.getB().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_BC) {
        Memory memory;
        memory.load({
            {0x0000, 0x41},
        });

        CPU cpu(memory);
        cpu.getC().set(10);

        cpu.execute();

        ASSERT_EQ(cpu.getB().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_BD) {
        Memory memory;
        memory.load({
            {0x0000, 0x42},
        });

        CPU cpu(memory);
        cpu.getD().set(10);

        cpu.execute();

        ASSERT_EQ(cpu.getB().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_BE) {
        Memory memory;
        memory.load({
            {0x0000, 0x43},
        });

        CPU cpu(memory);
        cpu.getE().set(10);

        cpu.execute();

        ASSERT_EQ(cpu.getB().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_BH) {
        Memory memory;
        memory.load({
            {0x0000, 0x44},
        });

        CPU cpu(memory);
        cpu.getH().set(10);

        cpu.execute();

        ASSERT_EQ(cpu.getB().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_BL) {
        Memory memory;
        memory.load({
            {0x0000, 0x45},
        });

        CPU cpu(memory);
        cpu.getL().set(10);

        cpu.execute();

        ASSERT_EQ(cpu.getB().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }
} // namespace MimicBoy::Test
