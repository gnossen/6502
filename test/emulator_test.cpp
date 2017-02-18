#include "emulator.hpp"
#include <iostream>
#include <cstdint>
#include <cassert>

void setLowBit(Register* reg) {
    reg->value[0] |= 1;
}

class TestEmulator : public Emulator {
public:
    TestEmulator() : Emulator(246) {
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

    void testMoveMemToReg() {
        zero();
        uint16_t val = 0;
        memory[0] = 25;
        assert(val == 0);
        moveMemToReg(0, 0);
        registers[0]->read(&val);
        assert(val == 25);
    }

    void testMoveRegToMem() {
        zero();
        uint16_t val = 25;
        registers[0]->write(&val);
        assert(memory[0] == 0);
        moveRegToMem(0, 0);
        assert(memory[0] == 25);
    }

    void testModifyReg() {
        zero();
        modifyReg(0, setLowBit);
        assert(registers[0]->value[0] == 1);
    }

    void testOperations() {
        testMoveMemToReg();
        testMoveRegToMem();
        testModifyReg();
    }
};

int main(int argc, char** argv) {
    auto emu = TestEmulator();
    emu.testAddRegister();
    emu.testZero();
    emu.testOperations();
    return 0;
}
