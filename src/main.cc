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
        {0x0000, 0x46},
        {0x0001, 20}
    });

    MimicBoy::CPU cpu(memory);
    cpu.setHL(0x0001);

    cpu.execute();

    return 0;
}
