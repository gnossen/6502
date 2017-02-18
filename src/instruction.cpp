#include "instruction.hpp"
#include <iostream>

Register* Instruction::getRegister(Emulator* emu, size_t regIndex) const {
    return emu->registers[regIndex];
}

uint8_t* Instruction::getMemory(Emulator* emu, uint32_t memAddress) const {
    return &emu->memory[memAddress];
}

void MoveRegToMemInstruction::execute(Emulator* emu) const {
    getRegister(emu, regIndex)->read((void*) getMemory(emu, memAddress));
}

void MoveMemToRegInstruction::execute(Emulator* emu) const {
    getRegister(emu, regIndex)->write((void*) getMemory(emu, memAddress));
}

void LoadRegisterInstruction::execute(Emulator* emu) const {
    getRegister(emu, regIndex)->write((void*) &value);
}

void SetFlagInstruction::execute(Emulator* emu) const {
    getRegister(emu, regIndex)->value[0] |= 1 << flagIndex;
}
