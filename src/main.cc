#include <iostream>
#include "Memory.h"

/**
 * The main entry point of the program.
 *
 * @return Returns zero upon successful execution of the program.
 */
int main() {
    MimicBoy::Memory memory;

    return memory.read(0xFFFF);

    return 0;
}


