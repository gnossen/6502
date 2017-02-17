#include "emulator.hpp"
#include <iostream>
#include <cstdint>

int main(int argc, char** argv) {
    auto emu = Emulator();
    std::cout << "Register State" << std::endl;
    std::cout << emu.getRegisters();
    return 0;
}
