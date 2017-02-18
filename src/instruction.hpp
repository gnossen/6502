#ifndef __INSTRUCTION__
#define __INSTRUCTION__

#include "i_emulator.hpp"
#include "register.hpp"

class Instruction {
public:
    virtual void execute(IEmulator* emu) = 0;
};

class LoadImmediate : public Instruction {
public:
    value = _value;
    LoadImmediate(size_t regIndex, uint8_t _value) {
        value = _value;
    }

    void execute(IEmulator* emu) {
        
    }
}

#endif
