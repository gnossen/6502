#include "emulator.hpp"
#include <iostream>

Emulator::Emulator() : Emulator(DefaultMemorySize) {}

Emulator::Emulator(const unsigned _memorySize) {
    memorySize = _memorySize;
    memory = new uint8_t[memorySize];
    populateRegisters();
    zero();
}

Emulator::~Emulator() {
    for (auto it = registers.begin(); it != registers.end(); it++) {
        delete *it;
    }
}

void Emulator::populateRegisters() {}

void Emulator::addRegister(const string& name, const int size) {
    auto reg = new Register(name, size);
    registers.push_back(reg);
}

void Emulator::zero() {
    zeroRegisters();
    zeroMemory();
}

void Emulator::zeroRegisters() {
    for_each(registers.begin(), registers.end(), [](Register* reg) {
        reg->zero();        
    });
}

void Emulator::zeroMemory() {
    memset((void*) memory, 0, memorySize);
}

string Emulator::getRegisters() const {
    ostringstream os;
    for (auto it = registers.begin(); it != registers.end(); it++) {
        os << (string) **it << std::endl;
    }
    return os.str();
}
