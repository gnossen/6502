#ifndef __I_EMULATOR__
#define __I_EMULATOR__

class IEmulator {
    virtual void moveMemToReg(uint32_t addr, size_t regIndex) = 0;
    virtual void moveRegToMem(size_t regIndex, uint32_t addr) = 0;
    virtual void modifyReg(size_t regIndex, void (*op) (Register*)) = 0;
};

#endif
