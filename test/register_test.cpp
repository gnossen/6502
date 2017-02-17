#include "register.hpp"
#include <iostream>
#include <cstdint>
#include <cassert>

int main() {
    auto pc = new Register("PC", 2);
    uint16_t val;
    pc->read(&val);
    assert(val == 0);

    uint16_t val2 = 7;
    val = 1025;
    pc->write(&val);
    pc->read(&val2);
    assert(val2 == 1025);

    assert((string) *pc == "PC: 1025");
    return 0;
}
