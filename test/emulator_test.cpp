#include "emulator.hpp"
#include <iostream>
#include <cstdint>
#include <cassert>

class TestEmulator : public Emulator {
public:
    TestEmulator() : Emulator() {
        assert(registers.size() > 0);
    }

    void testAddRegister() {
        unsigned oldSize = registers.size();
        addRegister("A", 2);
        assert(registers.size() == oldSize + 1);
        auto regPair = registers.find("A");
        assert(regPair != registers.end());
        auto reg = regPair->second;
        assert(reg->size == 2);
        assert(reg->name == "A");
    }
};

int main(int argc, char** argv) {
    auto emu = TestEmulator();
    emu.testAddRegister();
    return 0;
}
