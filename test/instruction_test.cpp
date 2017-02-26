#include "emulator6502.hpp"
#include "instruction.hpp"
#include <cassert>

using namespace std;

void executeInst(Emulator* emu, Register6502 reg, uint8_t opCode, uint8_t initValue, uint8_t arg, uint8_t result) {
    *emu->registers[reg]->value = initValue;
    assert(*emu->registers[reg]->value == 9);
    *emu->registers[ProgramCounter]->value = 32;
    emu->memory[32] = opCode;
    emu->memory[33] = arg;
    assert(*emu->registers[reg]->value == result);
}

void testAnd() {
    Emulator6502 emu(512); 
    executeInst(&emu, Accumulator, 0x29, 9, 7, 1);
    emu.zero();
    emu.memory[4] = 7;
    executeInst(&emu, Accumulator, 0x2D, 9, 4, 1);
}

int main(int argc, char** argv) {
    init_jumptable();
    return 0;
}
