#include "emulator.hpp"
#include <iostream>
#include <cstdint>
#include <cassert>

class TestEmulator : public Emulator {
public:
    TestEmulator() : Emulator(1024) {
        assert(registers.size() > 0);
        assert(memorySize == 1024);
    }

    void testAddRegister() {
        unsigned oldSize = registers.size();
        addRegister("A", 2);
        assert(registers.size() == oldSize + 1);
        auto reg = registers.back();
        assert(reg->size == 2);
        assert(reg->name == "A");
    }
};

int main(int argc, char** argv) {
    auto emu = TestEmulator();
    emu.testAddRegister();
    return 0;
}
