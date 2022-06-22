#include "BusJacker_Internal_Operations.h"

#define consoleDEBUG 0

void displayByteAsBits(uint8_t byte)
{
    Serial.print(byte);
    Serial.print(" 0[");

    for (int i = 1; i < 8; i++)
    {
        if (byte & 1)
            Serial.print(1);
        else
            Serial.print(0);
        byte >>= 1;
    }

    Serial.print("]7 ");
}

void setupClockControlPins(void)
{
    pinMode(CC_A0, OUTPUT);
    pinMode(CC_A1, OUTPUT);
    pinMode(CC_A2, OUTPUT);
    pinMode(CC_Pulse, OUTPUT);

    digitalWrite(CC_A0, LOW);
    digitalWrite(CC_A1, LOW);
    digitalWrite(CC_A2, LOW);
    digitalWrite(CC_Pulse, LOW);
}

void setupSregBusPins(void)
{
    pinMode(SRegBus_In_ShiftLoad_Pin, OUTPUT);
    pinMode(SRegBus_In_Data_Pin, INPUT);
    pinMode(SRegBus_Out_Data_Pin, OUTPUT);

    digitalWrite(SRegBus_In_ShiftLoad_Pin, HIGH);
    digitalWrite(SRegBus_Out_Data_Pin, HIGH);
    clearSregBus_Out();
}

void setup_BUSJacker(void)
{
    setupClockControlPins();
    setupSregBusPins();

    setRegControlLines_Out(0xFF);
    setRegAddrLo_Out(0xFF);
    setRegAddrHi_Out(0xFF);
}

void setCC_AddrLines(uint8_t CCAddr)
{
    CC_PORT = CC_PORT & CCAddr_MASK;

    CCAddr <<= 5;
    CC_PORT |= CCAddr;
}

void sendCCPulse(void)
{
    bitSet(PORTD, CC_Pulse);
    bitClear(PORTD, CC_Pulse);
}

void sendCCPulseToCCAddr(uint8_t CCAddr)
{
    setCC_AddrLines(CCAddr);
    sendCCPulse();
}

void setSregBus_Out(uint8_t byte)
{
    setCC_AddrLines(CCAddr_SRegBus_Out);
    for (int i = 8; i > 0; --i)
    {
        if (byte & 128)
        {
            // digitalWrite(SregBus_Out_DATA, HIGH);
            bitSet(SRegBus_PORT, SRegBus_Out_Data_Bit);
        }
        else
        {
            // digitalWrite(SregBus_Out_DATA, LOW);
            bitClear(SRegBus_PORT, SRegBus_Out_Data_Bit);
        }
        sendCCPulse();
        byte <<= 1;
    }
}

void clearSregBus_Out(void)
{
    setSregBus_Out(255);
}

void loadSregBus_In(void)
{
    bitClear(SRegBus_PORT, SRegBus_In_ShiftLoad_Bit);
    sendCCPulseToCCAddr(CCAddr_SRegBus_In);
    bitSet(SRegBus_PORT, SRegBus_In_ShiftLoad_Bit);
}

uint8_t getDataFromSregBus_In(void)
{
    setCC_AddrLines(CCAddr_SRegBus_In);

    uint8_t byte = 0;
    for (int i = 0; i < 8; i++)
    {
        byte <<= 1;
        // byte |= digitalRead(SRegBus_In_Data_Pin);
        byte |= bitRead(SRegBus_PORT, SRegBus_Out_Data_Bit);
        sendCCPulse();
    }
    return byte;
}

uint8_t loadAndGetDataFromSregBus_In(void)
{
    loadSregBus_In();
    return getDataFromSregBus_In();
}

void setRegControlLines_Out(uint8_t byte)
{
    setSregBus_Out(byte);
    sendCCPulseToCCAddr(CCAddr_RegControlLines_Out);
}

void setRegAddrLo_Out(uint8_t loByte)
{
    setSregBus_Out(loByte);
    sendCCPulseToCCAddr(CCAddr_RegAddrHi_Out);
}

void setRegAddrHi_Out(uint8_t hiByte)
{
    setSregBus_Out(hiByte);
    sendCCPulseToCCAddr(CCAddr_RegAddrLo_Out);
}

void sendCCPulseToHost(void)
{
    sendCCPulseToCCAddr(CCAddr_Host);
}
