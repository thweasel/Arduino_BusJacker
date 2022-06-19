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
    setZXAddrHi(AddressHi);

    //Serial.print("\nAddressHiReg: ");
    //displayByte(AddressHiReg);

    return;
}

void setAddressLoByte(uint8_t AddressLo)
{
    AddressLoReg = AddressLo;
    setZXAddrLo(AddressLoReg);

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

void setMaskBit_ON_Reg(uint8_t mask, uint8_t *reg)
{
    *reg |= mask;
    return;
}

void setMaskBit_OFF_Reg(uint8_t mask, uint8_t *reg)
{
    *reg ^= mask;
    return;
}

uint8_t getControlReg(void)
{
    return ControlReg;
}

void startBUSRQ(void)
{
    setMaskBit_OFF_Reg(mask_BUSRQ, &ControlReg);
    setZXControl(ControlReg);
}

void endBUSRQ(void)
{
    setMaskBit_ON_Reg(mask_BUSRQ, &ControlReg);
    setZXControl(ControlReg);
}

void startMEMRQ(void)
{
    setMaskBit_OFF_Reg(mask_MEMRQ, &ControlReg);
    setZXControl(ControlReg);
}

void endMEMRQ(void)
{
    setMaskBit_ON_Reg(mask_MEMRQ, &ControlReg);
    setZXControl(ControlReg);
}

void startRead(void)
{
    setMaskBit_OFF_Reg(mask_RD, &ControlReg);
    setZXControl(ControlReg);
}

void endRead(void)
{
    setMaskBit_ON_Reg(mask_RD, &ControlReg);
    setZXControl(ControlReg);
}

void startWrite(void)
{
    setMaskBit_OFF_Reg(mask_MEMRQ, &ControlReg);

    setMaskBit_OFF_Reg(mask_WR, &ControlReg);
    setZXControl(ControlReg);
}

void endWrite(void)
{
    setMaskBit_ON_Reg(mask_MEMRQ, &ControlReg);

    setMaskBit_ON_Reg(mask_WR, &ControlReg);
    setZXControl(ControlReg);
}

void writeData(uint8_t data)
{
    startWrite();    
    setBUS(data);
    pulseAccessZXDataBus();
    endWrite();
}

void writeOneByteToMemory(uint16_t Address, uint8_t Data)
{
    setAddress(Address);
    startBUSRQ();    
    //startMEMRQ();   
    writeData(Data);
    //endMEMRQ();
    endBUSRQ();
}

void writeTwoBytesToMemory(uint16_t Address, uint8_t Data)
{
    setAddress(Address);
    startBUSRQ();    
    startMEMRQ();   
    writeData(Data);
    
    setAddress(Address);
    writeData(Data);
    
    endMEMRQ();
    endBUSRQ();
}