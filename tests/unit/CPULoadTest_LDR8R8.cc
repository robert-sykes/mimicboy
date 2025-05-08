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

    // Tests for loading into C register (0x48-0x4D)
    TEST(CPUTest, ExecuteLDR8R8_CB) {
        Memory memory;
        memory.load({{0x0000, 0x48}});
        CPU cpu(memory);
        cpu.getB().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getC().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_CC) {
        Memory memory;
        memory.load({{0x0000, 0x49}});
        CPU cpu(memory);
        cpu.getC().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getC().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_CD) {
        Memory memory;
        memory.load({{0x0000, 0x4A}});
        CPU cpu(memory);
        cpu.getD().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getC().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_CE) {
        Memory memory;
        memory.load({{0x0000, 0x4B}});
        CPU cpu(memory);
        cpu.getE().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getC().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_CH) {
        Memory memory;
        memory.load({{0x0000, 0x4C}});
        CPU cpu(memory);
        cpu.getH().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getC().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_CL) {
        Memory memory;
        memory.load({{0x0000, 0x4D}});
        CPU cpu(memory);
        cpu.getL().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getC().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    // Tests for loading into D register (0x50-0x55)
    TEST(CPUTest, ExecuteLDR8R8_DB) {
        Memory memory;
        memory.load({{0x0000, 0x50}});
        CPU cpu(memory);
        cpu.getB().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getD().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_DC) {
        Memory memory;
        memory.load({{0x0000, 0x51}});
        CPU cpu(memory);
        cpu.getC().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getD().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_DD) {
        Memory memory;
        memory.load({{0x0000, 0x52}});
        CPU cpu(memory);
        cpu.getD().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getD().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_DE) {
        Memory memory;
        memory.load({{0x0000, 0x53}});
        CPU cpu(memory);
        cpu.getE().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getD().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_DH) {
        Memory memory;
        memory.load({{0x0000, 0x54}});
        CPU cpu(memory);
        cpu.getH().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getD().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_DL) {
        Memory memory;
        memory.load({{0x0000, 0x55}});
        CPU cpu(memory);
        cpu.getL().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getD().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    // Tests for loading into E register (0x58-0x5D)
    TEST(CPUTest, ExecuteLDR8R8_EB) {
        Memory memory;
        memory.load({{0x0000, 0x58}});
        CPU cpu(memory);
        cpu.getB().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getE().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_EC) {
        Memory memory;
        memory.load({{0x0000, 0x59}});
        CPU cpu(memory);
        cpu.getC().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getE().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_ED) {
        Memory memory;
        memory.load({{0x0000, 0x5A}});
        CPU cpu(memory);
        cpu.getD().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getE().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_EE) {
        Memory memory;
        memory.load({{0x0000, 0x5B}});
        CPU cpu(memory);
        cpu.getE().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getE().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_EH) {
        Memory memory;
        memory.load({{0x0000, 0x5C}});
        CPU cpu(memory);
        cpu.getH().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getE().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_EL) {
        Memory memory;
        memory.load({{0x0000, 0x5D}});
        CPU cpu(memory);
        cpu.getL().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getE().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    // Tests for loading into H register (0x60-0x65)
    TEST(CPUTest, ExecuteLDR8R8_HB) {
        Memory memory;
        memory.load({{0x0000, 0x60}});
        CPU cpu(memory);
        cpu.getB().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getH().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_HC) {
        Memory memory;
        memory.load({{0x0000, 0x61}});
        CPU cpu(memory);
        cpu.getC().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getH().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_HD) {
        Memory memory;
        memory.load({{0x0000, 0x62}});
        CPU cpu(memory);
        cpu.getD().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getH().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_HE) {
        Memory memory;
        memory.load({{0x0000, 0x63}});
        CPU cpu(memory);
        cpu.getE().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getH().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_HH) {
        Memory memory;
        memory.load({{0x0000, 0x64}});
        CPU cpu(memory);
        cpu.getH().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getH().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_HL) {
        Memory memory;
        memory.load({{0x0000, 0x65}});
        CPU cpu(memory);
        cpu.getL().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getH().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    // Tests for loading into L register (0x68-0x6D)
    TEST(CPUTest, ExecuteLDR8R8_LB) {
        Memory memory;
        memory.load({{0x0000, 0x68}});
        CPU cpu(memory);
        cpu.getB().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getL().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_LC) {
        Memory memory;
        memory.load({{0x0000, 0x69}});
        CPU cpu(memory);
        cpu.getC().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getL().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_LD) {
        Memory memory;
        memory.load({{0x0000, 0x6A}});
        CPU cpu(memory);
        cpu.getD().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getL().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_LE) {
        Memory memory;
        memory.load({{0x0000, 0x6B}});
        CPU cpu(memory);
        cpu.getE().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getL().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_LH) {
        Memory memory;
        memory.load({{0x0000, 0x6C}});
        CPU cpu(memory);
        cpu.getH().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getL().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_LL) {
        Memory memory;
        memory.load({{0x0000, 0x6D}});
        CPU cpu(memory);
        cpu.getL().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getL().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    // Tests for loading into A register (0x78-0x7D)
    TEST(CPUTest, ExecuteLDR8R8_AB) {
        Memory memory;
        memory.load({{0x0000, 0x78}});
        CPU cpu(memory);
        cpu.getB().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getA().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_AC) {
        Memory memory;
        memory.load({{0x0000, 0x79}});
        CPU cpu(memory);
        cpu.getC().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getA().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_AD) {
        Memory memory;
        memory.load({{0x0000, 0x7A}});
        CPU cpu(memory);
        cpu.getD().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getA().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_AE) {
        Memory memory;
        memory.load({{0x0000, 0x7B}});
        CPU cpu(memory);
        cpu.getE().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getA().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_AH) {
        Memory memory;
        memory.load({{0x0000, 0x7C}});
        CPU cpu(memory);
        cpu.getH().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getA().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }

    TEST(CPUTest, ExecuteLDR8R8_AL) {
        Memory memory;
        memory.load({{0x0000, 0x7D}});
        CPU cpu(memory);
        cpu.getL().set(10);
        cpu.execute();
        ASSERT_EQ(cpu.getA().get(), 10);
        ASSERT_EQ(cpu.getPC(), 0x0001);
    }
} // namespace MimicBoy::Test
