#include "register.hpp"
#include <iostream>
#include <cstdint>
#include <cassert>

void setLowBit(Register* reg) {

}

void testRead() {
    auto pc = new Register("PC", 2);
    uint16_t val;
    pc->read(&val);
    assert(val == 0);
}

void testWrite() {
    auto pc = new Register("PC", 2);
    uint16_t val = 1025;
    uint16_t val2 = 7;
    pc->write(&val);
    pc->read(&val2);
    assert(val2 == 1025);
}

void testString() {
    auto pc = new Register("PC", 2);
    uint16_t val = 1025;
    pc->write(&val);
    assert((string) *pc == "PC: 1025");
}

void testZero() {
    auto pc = new Register("PC", 2);
    uint8_t val = 5;
    pc->zero();
    pc->read(&val);
    assert(val == 0);
}

int main() {
    testRead();
    testWrite();
    testString();
    testZero();

    return 0;
}
