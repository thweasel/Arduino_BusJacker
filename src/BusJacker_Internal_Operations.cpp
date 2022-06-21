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
    pinMode(CC_TICK, OUTPUT);

    digitalWrite(CC_A0, LOW);
    digitalWrite(CC_A1, LOW);
    digitalWrite(CC_A2, LOW);
    digitalWrite(CC_TICK, LOW);
}

void setupSregBusPins(void)
{
    pinMode(SRegBus_In_ShiftLoadPin, OUTPUT);
    pinMode(SRegBus_In_DataPin, INPUT);
    pinMode(SRegBus_Out_DataPin, OUTPUT);

    digitalWrite(SRegBus_In_ShiftLoadPin, HIGH);
    digitalWrite(SRegBus_Out_DataPin, HIGH);
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
    bitSet(PORTD, CC_TICK);
    bitClear(PORTD, CC_TICK);
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
            bitSet(SRegBus_PORT, SRegBus_Out_DataBit);
        }
        else
        {
            // digitalWrite(SregBus_Out_DATA, LOW);
            bitClear(SRegBus_PORT, SRegBus_Out_DataBit);
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
    bitClear(SRegBus_PORT, SRegBus_In_ShiftLoadBit);
    sendCCPulseToCCAddr(CCAddr_SRegBus_In);
    bitSet(SRegBus_PORT, SRegBus_In_ShiftLoadBit);
}

uint8_t getDataFromSregBus_In(void)
{
    setCC_AddrLines(CCAddr_SRegBus_In);

    uint8_t byte = 0;
    for (int i = 0; i < 8; i++)
    {
        byte <<= 1;
        // byte |= digitalRead(SRegBus_In_DataPin);
        byte |= bitRead(SRegBus_PORT, SRegBus_Out_DataBit);
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
    sendCCPulseToCCAddr(CCAddr_HostSystem);
}
