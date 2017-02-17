#include "emulator.hpp"

Emulator::Emulator() {
    addRegister("PC", 2);
}

Emulator::~Emulator() {
    for (auto it = registers.begin(); it != registers.end(); it++) {
        delete it->second;
    }
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
