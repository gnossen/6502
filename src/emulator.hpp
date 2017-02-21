#ifndef __EMULATOR__
#define __EMULATOR__

#include <cstdint>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include "register.hpp"
#include "instruction.hpp"

using namespace std;

class Instruction;

const int DefaultMemorySize = 65536;

class Emulator {
private:
    void populateRegisters();

protected:
    unsigned memorySize;

    void addRegister(const string& name, int size);
    void zeroRegisters();
    void zeroMemory();

public:
    vector<Register*> registers;
    uint8_t* memory;

    Emulator();
    Emulator(const unsigned memorySize);
    ~Emulator();

    void execute(Instruction* inst);
    void zero();

    string getRegisters() const;

    friend class Instruction;
};

#endif
