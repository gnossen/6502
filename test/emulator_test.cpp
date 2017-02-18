#include "emulator.hpp"
#include <iostream>
#include <cstdint>
#include <cassert>

void setLowBit(Register* reg) {
    reg->value[0] |= 1;
}

class TestEmulator : public Emulator {
public:
    TestEmulator() : Emulator(256) {
        assert(registers.size() > 0);
        assert(memorySize == 256);
    }

    void testAddRegister() {
        unsigned oldSize = registers.size();
        addRegister("A", 2);
        assert(registers.size() == oldSize + 1);
        auto reg = registers.back();
        assert(reg->size == 2);
        assert(reg->name == "A");
    }

    void testZero() {
        zero();
        uint8_t* p = memory;
        for (size_t i = 0; i < memorySize; ++i) {
            assert(*p == 0);
            ++p;
        }
        uint64_t val = 0;
        for (auto reg = registers.begin(); reg != registers.end(); ++reg) {
            (*reg)->read(&val);
            assert(val == 0);
        }
    }

};

int main(int argc, char** argv) {
    auto emu = TestEmulator();
    emu.testAddRegister();
    emu.testZero();
    return 0;
}
