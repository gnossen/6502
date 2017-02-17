#ifndef __EMULATOR__
#define __EMULATOR__

#include <cstdint>
#include <cstdio>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

struct Register {
    string name;
    size_t size;
    uint8_t* value;

    Register(string _name, size_t _size) {
        name = _name;
        size = _size;
        value = new uint8_t[size];
        zero();
    }

    ~Register() {
        delete [] value;
    }

    void read(void* dst) const {
        memcpy(dst, (void*) value, size);
    }

    void write(void* src) {
        memcpy((void*) value, src, size);
    }

    void zero() {
        for (size_t i = 0; i < size; i++) {
            value[i] = 0;
        }
    }

    operator auto() const {
        ostringstream os;
        uint64_t fullVal = 0;
        memcpy((void*) &fullVal, (void*) value, size);
        os << name << ": " << fullVal;
        return os.str();
    }
};

const int DefaultMemorySize = 65536;

class Emulator {
private:
    void populateRegisters();

protected:
    map<string, Register*> registers;
    uint8_t* memory;
    unsigned memorySize;

    void addRegister(const string& name, int size);

public:
    Emulator();
    Emulator(const unsigned memorySize);
    ~Emulator();

    string getRegisters() const;
};

#endif
