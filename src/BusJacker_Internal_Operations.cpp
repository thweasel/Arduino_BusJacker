#include "BusJacker_Internal_Operations.h"

#define consoleDEBUG 0

void displayByte(uint8_t byte)
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
    pinMode(ShiftLoad_DATA_IN, OUTPUT);
    pinMode(DATA_IN, INPUT);
    pinMode(DATA_OUT, OUTPUT);

    digitalWrite(ShiftLoad_DATA_IN, HIGH);
    digitalWrite(DATA_OUT, HIGH);
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
    // DEBUG
    //Serial.print("\nCC_ADDR: ");
    //Serial.print(CCAddr);

    CC_PORT = CC_PORT & CCAddr_MASK;

    CCAddr <<= 5;
    CC_PORT |= CCAddr;
    return;
}

void sendCCPulse(void)
{
    //digitalWrite(CC_TICK, HIGH);
    //digitalWrite(CC_TICK, LOW);
    
    //delay(20);
    //delayMicroseconds(2);
    
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
            //digitalWrite(DATA_OUT, HIGH);
            bitSet(PORTC,DATA_OUT-14);
        }
        else
        {
            //digitalWrite(DATA_OUT, LOW);
            bitClear(PORTC,DATA_OUT-14);
        }
        sendCCPulse();
        byte <<= 1;
    }
    return;
}

void clearSregBus_Out(void)
{
    setSregBus_Out(255);
}

void loadSregBus_In(void)
{
    //digitalWrite(ShiftLoad_DATA_IN, DATA_IN_LOAD);
    //clearSregOut();
    bitClear(PORTC,ShiftLoad_DATA_IN-14);
    sendCCPulseToCCAddr(CCAddr_SRegBus_In);
    bitSet(PORTC,ShiftLoad_DATA_IN-14);
    // DEBUG
    //Serial.print("  loadSregBus_In");
}

uint8_t getDataFromSregBus_In(void)
{
    //bitSet(PORTC,ShiftLoad_DATA_IN-14);
    setCC_AddrLines(CCAddr_SRegBus_In);

    uint8_t byte = 0;
    for (int i = 0; i < 8; i++)
    {
        byte <<= 1;
        byte |= digitalRead(DATA_IN);
        sendCCPulse();
    }

    return byte;

}

uint8_t loadAndGetDataFromSregBus_In(void)
{
    // Load the ShiftReg
    loadSregBus_In();

    // Read in the ShiftReg
    return getDataFromSregBus_In();

}

void setRegControlLines_Out(uint8_t byte)
{
    setSregBus_Out(byte);
    sendCCPulseToCCAddr(CCAddr_RegControlLines_Out);

    if (consoleDEBUG)
    {
        Serial.print("\nZX_Control: ");
        displayByte(byte);
    }
}

void setRegAddrLo_Out(uint8_t loByte)
{
    setSregBus_Out(loByte);
    sendCCPulseToCCAddr(CCAddr_RegAddrHi_Out);

    if (consoleDEBUG)
    {
        Serial.print("\nZX_AddrLo: ");
        displayByte(loByte);
    }
}

void setRegAddrHi_Out(uint8_t hiByte)
{
    setSregBus_Out(hiByte);
    sendCCPulseToCCAddr(CCAddr_RegAddrLo_Out);

    if (consoleDEBUG)
    {
        Serial.print("\nZX_AddrHi: ");
        displayByte(hiByte);
    }
}

void sendCCPulseToHostSystem(void)
{
    sendCCPulseToCCAddr(CCAddr_HostSystem);
}