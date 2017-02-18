#include "emulator.hpp"

Emulator::Emulator() : Emulator(DefaultMemorySize) {}

Emulator::Emulator(const unsigned _memorySize) {
    populateRegisters();
    memorySize = _memorySize;
    memory = new uint8_t[memorySize];
}

Emulator::~Emulator() {
    for (auto it = registers.begin(); it != registers.end(); it++) {
        delete *it;
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
    registers.push_back(reg);
}

void Emulator::moveMemToReg(uint32_t addr, size_t regIndex) {
    registers[regIndex]->read((void*) &memory[addr]);
}

void Emulator::moveRegToMem(size_t regIndex, uint32_t addr) {
    registers[regIndex]->write((void*) &memory[addr]);
}

void Emulator::modifyReg(size_t regIndex, void (*op) (Register*)) {
    op(registers[regIndex]);
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
