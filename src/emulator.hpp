#ifndef __EMULATOR__
#define __EMULATOR__

#include <cstdint>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include "register.hpp"

using namespace std;

const int DefaultMemorySize = 65536;

class Emulator {
private:
    void populateRegisters();

protected:
    vector<Register*> registers;
    uint8_t* memory;
    unsigned memorySize;

    void addRegister(const string& name, int size);
    void zeroRegisters();
    void zeroMemory();

public:
    Emulator();
    Emulator(const unsigned memorySize);
    ~Emulator();

    void moveMemToReg(uint32_t addr, size_t regIndex);
    void moveRegToMem(size_t regIndex, uint32_t addr);
    void modifyReg(size_t regIndex, void (*op) (Register*));

    void zero();

    string getRegisters() const;
};

#endif
