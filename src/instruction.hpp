#ifndef __INSTRUCTION__
#define __INSTRUCTION__

#include <cstdint>
#include <cstdio>
#include <string>
#include "emulator.hpp"
#include "register.hpp"

class Emulator;

using namespace std;

class Instruction {
public:
    virtual void execute(Emulator* emu) const = 0;
    virtual string toString() const = 0;
    virtual uint8_t* toBytes() const = 0;
    virtual size_t byteLen() const = 0;
}; 

class Address

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

    void execute(Emulator* emu) const;
};

class SetFlagInstruction : public Instruction {
protected:
    size_t regIndex;
    size_t flagIndex;

public:
    SetFlagInstruction(size_t _regIndex, size_t _flagIndex) {
        regIndex = _regIndex; 
        flagIndex = _flagIndex;
    }

    void execute(Emulator* emu) const;
};

#endif
