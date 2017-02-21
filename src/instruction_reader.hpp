#ifndef INSRUCTION_READER_H
#define INSRUCTION_READER_H

#include <cstdint>
#include <cstdio>
#include <pair>
#include "instruction.h"

class InstructionReader {
public:
    virtual Instruction read(uint8_t* data) const = 0;
};

class Reader6502 : public InstructionReader {
public: 
    Reader6502() {}
    Instruction read(uint8_t* data) const;
}

#endif
