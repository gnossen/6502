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

// template <>
// using byte_t<1> = uint8_t;
// 
// template <>
// using byte_t<2> = uint16_t;
// 
// template <>
// using byte_t<4> = uint32_t;
// 
// template <>
// using byte_t<8> = uint64_t;
// 
// class LoadRegisterInstruction : public Instruction {
// protected:
//     size_t regIndex;
// 
// public:
//     virtual void execute(Emulator* emu) const = 0;
// };
// 
// template <int N>
// class LoadRegister : public LoadRegisterInstruction {
// protected:
//     byte_t<N> value;
// 
// public:
//     LoadRegister(size_t _regIndex, byte_t<N> value) {
//         regIndex = _regIndex;
//         value = _value;
//     }
// 
//     void execute(Emulator* emu) const {
// 
// class LoadRegisterInstruction : public Instruction {
// protected:
//     size_t regIndex;
// 
// public:
//     virtual void execute(Emulator* emu) const = 0;
// };
// 
// template <int N>
// class LoadRegister : public LoadRegisterInstruction {
// protected:
//     byte_t<N> value;
// 
// public:
//     LoadRegister(size_t _regIndex, byte_t<N> value) {
//         regIndex = _regIndex;
//         value = _value;
//     }
// 
//     void execute(Emulator* emu) const {
//         emu->registers[regIndex]->write((void*) &value);
//     }
// };

#endif
