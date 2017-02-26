#ifndef EMULATOR_6502_H
#define EMULATOR_6502_H

#include "emulator.hpp"

typedef enum Register6502 {
    ProgramCounter = (size_t) 0,
    StackPointer = (size_t) 1,
    Accumulator = (size_t) 2,
    RegisterX = (size_t) 3,
    RegisterY = (size_t) 4,
    StatusRegister = (size_t) 5
} Register6502;

class Emulator6502 : public Emulator {

protected:
    void populateRegisters() {
        addRegister("PC", 2);
        addRegister("SP", 1);
        addRegister("ACC", 1);
        addRegister("X", 1);
        addRegister("Y", 1);
        addRegister("STATUS", 1);
    }

public:

    Emulator6502() : Emulator() {}
    Emulator6502(const unsigned memorySize) : Emulator(memorySize) {}
};
#endif
