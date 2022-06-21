#include "BusJacker_Z80_Operations.h"

#define mask_BUSRQ B00000001
#define mask_MEMRQ B00000010
#define mask_RD B00000100
#define mask_WR B00001000

// Maintain a runtime Model of the BusJacker, all lines default to High
uint8_t ControlReg = 0xFF,
        AddressHiReg = 0xFF,
        AddressLoReg = 0xFF;

//
//  Address BUS methods
//

uint8_t getAddressHiReg(void)
{
    return AddressHiReg;
}

uint8_t getAddressLoReg(void)
{
    return AddressLoReg;
}

uint16_t getAddress(void)
{
    uint16_t temp = (uint16_t)AddressHiReg;
    temp >>= 8;
    temp |= AddressLoReg;
    return temp;
}

void setAddressHiByte(uint8_t AddressHi)
{
    AddressHiReg = AddressHi;
    setRegAddrHi_Out(AddressHi);

    //Serial.print("\nAddressHiReg: ");
    //displayByte(AddressHiReg);

    return;
}

void setAddressLoByte(uint8_t AddressLo)
{
    AddressLoReg = AddressLo;
    setRegAddrLo_Out(AddressLoReg);

    //Serial.print("\nAddressLoReg: ");
    //displayByte(AddressLoReg);

    return;
}

void setAddress(uint16_t Address)
{
    setAddressLoByte((uint8_t)Address);
    Address >>= 8;
    setAddressHiByte((uint8_t)Address);
    return;
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
    return;
}

void setMaskedBits_OFF(uint8_t mask, uint8_t *reg)
{
    *reg ^= mask;
    return;
}

uint8_t getControlReg(void)
{
    return ControlReg;
}

// Stop system to take control with a BUS Request

void startBUSRQ(void)
{
    setMaskedBits_OFF(mask_BUSRQ, &ControlReg);
    setRegControlLines_Out(ControlReg);
}

void endBUSRQ(void)
{
    setMaskedBits_ON(mask_BUSRQ, &ControlReg);
    setRegControlLines_Out(ControlReg);
}

// Memory access

void startMemoryAccess_Read(void)
{
    setMaskedBits_OFF(mask_MEMRQ, &ControlReg);
    setMaskedBits_OFF(mask_RD, &ControlReg);
    setRegControlLines_Out(ControlReg);
}

void endMemoryAccess_Read(void)
{
    setMaskedBits_ON(mask_RD, &ControlReg);
    setMaskedBits_ON(mask_MEMRQ, &ControlReg);
    setRegControlLines_Out(ControlReg);
}

void startMemoryAccess_Write(void)
{
    setMaskedBits_OFF(mask_MEMRQ, &ControlReg);
    setMaskedBits_OFF(mask_WR, &ControlReg);
    setRegControlLines_Out(ControlReg);
}

void endMemoryAccess_Write(void)
{
    setMaskedBits_ON(mask_MEMRQ, &ControlReg);
    setMaskedBits_ON(mask_WR, &ControlReg);
    setRegControlLines_Out(ControlReg);
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