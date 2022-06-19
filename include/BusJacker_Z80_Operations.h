#include <Arduino.h> // Microcontroller dependent

#include "BusJacker_InternalBUS_Operations.h"

//
//  Address BUS methods
//

void setAddressLoByte(uint8_t AddressLo);
void setAddressHiByte(uint8_t AddressHi);
void setAddress(uint16_t Address);
void setAddressBUS_Passive(void);

//
//  Control BUS methods
//

uint8_t getControlReg(void);

void startBUSRQ(void);
void endBUSRQ(void);

void startMEMRQ(void);
void endMEMRQ(void);

void startRead(void);
void endRead(void);

void startWrite(void);
void endWrite(void);

void writeData(uint8_t data);

void writeOneByteToMemory(uint16_t Address, uint8_t Data);
void writeTwoBytesToMemory(uint16_t Address, uint8_t Data);