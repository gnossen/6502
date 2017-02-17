#ifndef __EMULATOR__
#define __EMULATOR__

#include <cstdint>
#include <cstdio>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

template <int N>
struct Register {
    string name;
    uint8_t value[N];

    void read(void* dst) {
        memcpy(dst, (void*) value, N);
    }

    void write(void* src) {
        memcpy((void*) value, src, N);
    }

    operator auto() const {
        ostringstream os;
        uint64_t fullVal = 0;
        memcpy((void*) &fullVal, (void*) value, N);
        os << name << ": " << fullVal;
        return os.str();
    }
};

#endif
