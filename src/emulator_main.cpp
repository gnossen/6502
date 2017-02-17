#include "emulator.hpp"
#include <iostream>
#include <cstdint>

int main(int argc, char** argv) {
    auto pc = new Register<2>();
    pc->name = "PC";
    uint16_t val;
    pc->read(&val);
    std::cout << (string) *pc << std::endl;
    val = 1025;
    std::cout << "Setting PC to 1025" << std::endl;
    pc->write(&val);
    pc->read(&val);
    std::cout << (string) *pc << std::endl;
    return 0;
}
