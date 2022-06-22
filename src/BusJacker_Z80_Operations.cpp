#include "BusJacker_Z80_Operations.h"

// Control line masks for control signals
#define mask_BUSRQ B00000001
#define mask_MEMRQ B00000010
#define mask_RD B00000100
#define mask_WR B00001000

// Maintain a runtime Model of the BusJacker registers, all lines default to High
uint8_t RegControlLines_Out = 0xFF,
        RegAddrHi_Out = 0xFF,
        RegAddrLo_Out = 0xFF;

//
//  Address BUS methods
//

uint8_t getAddressHiReg(void)
{
    return RegAddrHi_Out;
}

uint8_t getAddressLoReg(void)
{
    return RegAddrLo_Out;
}

uint16_t getAddress(void)
{
    uint16_t temp = (uint16_t)RegAddrHi_Out;
    temp >>= 8;
    temp |= RegAddrLo_Out;
    return temp;
}

void setAddressHiByte(uint8_t AddressHi)
{
    RegAddrHi_Out = AddressHi;
    setRegAddrHi_Out(AddressHi);
}

void setAddressLoByte(uint8_t AddressLo)
{
    RegAddrLo_Out = AddressLo;
    setRegAddrLo_Out(RegAddrLo_Out);
}

void setAddress(uint16_t Address)
{
    setAddressLoByte((uint8_t)Address);
    Address >>= 8;
    setAddressHiByte((uint8_t)Address);
}

void setAddressBUS_Passive(void)
{
    // The address BUS is passive to the system when high
    setAddress(0xFFFF);
}

//
//  Control BUS methods
//

void setMaskedBits_ON(uint8_t mask, uint8_t *reg)
{
    *reg |= mask;
}

void setMaskedBits_OFF(uint8_t mask, uint8_t *reg)
{
    *reg ^= mask;
}

uint8_t getControlReg(void)
{
    return RegControlLines_Out;
}

// Stop system to take control with a BUS Request (BUSRQ)

void startBUSRQ(void)
{
    setMaskedBits_OFF(mask_BUSRQ, &RegControlLines_Out);
    setRegControlLines_Out(RegControlLines_Out);
}

void endBUSRQ(void)
{
    setMaskedBits_ON(mask_BUSRQ, &RegControlLines_Out);
    setRegControlLines_Out(RegControlLines_Out);
}

// Memory access

void startMemoryAccess_Read(void)
{
    setMaskedBits_OFF(mask_MEMRQ, &RegControlLines_Out);
    setMaskedBits_OFF(mask_RD, &RegControlLines_Out);
    setRegControlLines_Out(RegControlLines_Out);
}

void endMemoryAccess_Read(void)
{
    setMaskedBits_ON(mask_RD, &RegControlLines_Out);
    setMaskedBits_ON(mask_MEMRQ, &RegControlLines_Out);
    setRegControlLines_Out(RegControlLines_Out);
}

void startMemoryAccess_Write(void)
{
    setMaskedBits_OFF(mask_MEMRQ, &RegControlLines_Out);
    setMaskedBits_OFF(mask_WR, &RegControlLines_Out);
    setRegControlLines_Out(RegControlLines_Out);
}

void endMemoryAccess_Write(void)
{
    setMaskedBits_ON(mask_MEMRQ, &RegControlLines_Out);
    setMaskedBits_ON(mask_WR, &RegControlLines_Out);
    setRegControlLines_Out(RegControlLines_Out);
}

void writeToHostDatabus(uint8_t data)
{    
    setSregBus_Out(data);
    sendCCPulseToHost();    
}

void writeByteToHostMemory(uint16_t Address, uint8_t Data)
{
    setAddress(Address);
    startBUSRQ();    
    startMemoryAccess_Write();     
    
    writeToHostDatabus(Data);
    
    endMemoryAccess_Write();
    endBUSRQ();
}

uint8_t readByteFromHostMemory(uint16_t Address)
{
    setAddress(Address);
    startBUSRQ();
    startMemoryAccess_Read();
    
    clearSregBus_Out(); // stop the SregOut putting data on the BUS (no OE)
    loadSregBus_In();
    
    endMemoryAccess_Read();    
    endBUSRQ();

    return getDataFromSregBus_In();
}