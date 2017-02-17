#ifndef __EMULATOR__
#define __EMULATOR__

#include <cstdint>
#include <vector>
#include <utility>
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

public:
    Emulator();
    Emulator(const unsigned memorySize);
    ~Emulator();

    void MoveMemToReg();

    string getRegisters() const;
};

#endif
