#include "Memory.h"
#include "CPU.h"

/**
 * The main entry point of the program.
 *
 * @return Returns zero upon successful execution of the program.
 */
int main() {
    MimicBoy::Memory memory;
    memory.load({
        {0x0000, 0x40}
    });

    MimicBoy::CPU cpu(memory);
    cpu.setB(0x01);
    cpu.setC(0x02);

    cpu.execute();

    return 0;
}
