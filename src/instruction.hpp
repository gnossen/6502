#ifndef __INSTRUCTION__
#define __INSTRUCTION__

#include <cstdint>
#include <cstdio>
#include "emulator.hpp"
#include "register.hpp"

class Emulator;

class Instruction {
public:
    virtual void execute(Emulator* emu) const = 0;

protected:
    Register* getRegister(Emulator* emu, size_t regIndex) const;
    uint8_t* getMemory(Emulator* emu, uint32_t memAddress) const;
};

class MoveRegToMemInstruction : public Instruction {
protected:
    size_t regIndex;
    uint32_t memAddress;

public:
    MoveRegToMemInstruction(size_t _regIndex, uint32_t _memAddress) {
        regIndex = _regIndex;
        memAddress = _memAddress;
    }

    void execute(Emulator* emu) const;
};

class MoveMemToRegInstruction : public Instruction {
protected:
    uint32_t memAddress;
    size_t regIndex;

public:
    MoveMemToRegInstruction(uint32_t _memAddress, size_t _regIndex) {
        memAddress = _memAddress;
        regIndex = _regIndex;
    }

    void execute(Emulator* emu) const;
};

class LoadRegisterInstruction : public Instruction {
protected:
    size_t regIndex;
    uint64_t value;

public:
    LoadRegisterInstruction(size_t _regIndex, uint8_t _value) {
        regIndex = _regIndex;
        value = (uint64_t)_value;
    }

    LoadRegisterInstruction(size_t _regIndex, uint16_t _value) {
        regIndex = _regIndex;
        value = (uint64_t)_value;
    }

    LoadRegisterInstruction(size_t _regIndex, uint32_t _value) {
        regIndex = _regIndex;
        value = (uint64_t)_value;
    }

    LoadRegisterInstruction(size_t _regIndex, uint64_t _value) {
        regIndex = _regIndex;
        value = _value;
    }

    virtual void execute(Emulator* emu) const {
        getRegister(emu, regIndex)->write((void*) &value);
    }
};

#endif
