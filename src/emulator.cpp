#include "emulator.hpp"


Emulator::Emulator() : Emulator(DefaultMemorySize) {}

Emulator::Emulator(const unsigned _memorySize) {
    populateRegisters();
    memorySize = _memorySize;
    memory = new uint8_t[memorySize];
}

Emulator::~Emulator() {
    for (auto it = registers.begin(); it != registers.end(); it++) {
        delete it->second;
    }
}

void Emulator::populateRegisters() {
    addRegister("PC", 2);
    addRegister("SP", 1);
    addRegister("ACC", 1);
    addRegister("X", 1);
    addRegister("Y", 1);
    addRegister("STATUS", 1);
}

void Emulator::addRegister(const string& name, const int size) {
    auto reg = new Register(name, size);
    registers.insert(make_pair(name, reg));
}

string Emulator::getRegisters() const {
    ostringstream os;
    for (auto it = registers.begin(); it != registers.end(); it++) {
        os << (string) *(it->second) << std::endl;
    }
    return os.str();
}
