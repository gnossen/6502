#include "emulator.hpp"
#include "instruction.hpp"
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>

class TestEmulator : public Emulator {
    public:
        TestEmulator() : Emulator(256) {
            addRegister("A", 1); 
        }

        void setMem(uint32_t address, uint8_t value) {
            memory[address] = value;
        }

        uint8_t getMem(uint32_t address) const {
            return memory[address];
        }

        void setReg(size_t regIndex, uint8_t value) {
            registers[regIndex]->write(&value);
        }

        uint8_t getReg(size_t regIndex) const {
            uint8_t val = 0;
            registers[regIndex]->read(&val);
            return val;
        }
};

void testMoveRegToMemInstruction() {
    auto emu = TestEmulator();
    emu.setReg(0, 7);
    assert(emu.getMem(0) == 0);

    auto inst = MoveRegToMemInstruction(0, 0);
    inst.execute(&emu);
    assert(emu.getMem(0) == 7);
}

void testMoveMemToRegInstruction() {
    auto emu = TestEmulator();
    emu.setMem(0, 7);
    assert(emu.getMem(0) == 7);
    assert(emu.getReg(0) == 0);

    auto inst = MoveMemToRegInstruction(0, 0);
    inst.execute(&emu);
    assert(emu.getReg(0) == 7);
}

int main(int argc, char** argv) {
    testMoveRegToMemInstruction();
    testMoveMemToRegInstruction();
    return 0;
}
