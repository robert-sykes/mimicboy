#include "Memory.h"
#include "CPU.h"

/**
 * The main entry point of the program.
 *
 * @return Returns zero upon successful execution of the program.
 */
int main() {
    MimicBoy::Memory memory;
    MimicBoy::CPU cpu(memory);

    cpu.execute();

    return 0;
}
