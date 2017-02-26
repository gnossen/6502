#include "emulator.hpp"

typedef void (*ExecPointer)(Emulator*, uint8_t*);

ExecPointer JumpTable[256];

typedef enum AddressingMode {
    IndexedIndirect,
    ZeroPage,
    Immediate,
    AccumulatorMode,
    IndirectIndexed,
    ZeroPageX,
    AbsoluteY,
    AbsoluteX,
    ZeroPageY,
    Relative,
    Absolute,
    Indirect
} AddressingMode;

struct Instruction {
    virtual void execute(Emulator* emu) const = 0;
    virtual string toString() const = 0;
    virtual uint8_t* toBytes() const = 0;
    virtual size_t byteLen() const = 0;
}; 

struct Instruction6502 : public Instruction {
    virtual void execute(Emulator* emu) const = 0;
    virtual string toString() const = 0;
    virtual uint8_t* toBytes() const = 0;
    virtual size_t byteLen() const = 0;

    static void ex(Emulator* emu) {
        uint8_t* pc = emu->registers[ProgramCounter]->value;
        JumpTable[*pc](emu, pc + 1);
    }
};

typedef enum InstructionType {
    AndInstruction    
} InstructionType;

template<typename InstKernel, typename ArgType, int AddressingMode, uint8_t OpCode>
struct Instruction6502X : public Instruction6502 {
    ArgType* arg;
    static const size_t argByteLen;

    static const uint8_t opCode = OpCode;
    static const string instName;

    static constexpr size_t byteLength = 1 + sizeof(ArgType);

    string toString() const {
        return "NOP";
    }

    uint8_t* toBytes() const {
        return NULL;
    }

    size_t byteLen() const {
        return byteLength;
    }

    static uint8_t* evalAddress(Emulator* emu, ArgType* _arg) {
        // default immediate mode
        return (uint8_t*) _arg;
    }

    static void executeStatic(Emulator* emu, uint8_t* _arg) {
        InstKernel::exec(emu, evalAddress(emu, _arg));        
        *emu->registers[ProgramCounter]->value += byteLength;
    }

    virtual void execute(Emulator* emu) const {
        executeStatic(emu, this->arg);
    }
};


struct AndInstKernel {
    static void exec(Emulator* emu, uint8_t* arg) {
        *emu->registers[Accumulator]->value &= *arg;
    }
};

void init_jumptable() {
    JumpTable[0x29] = &Instruction6502X<AndInstKernel, uint8_t, Immediate, 0x29>::executeStatic;
    JumpTable[0x2D] = &Instruction6502X<AndInstKernel, uint8_t, Absolute, 0x2D>::executeStatic;
}
