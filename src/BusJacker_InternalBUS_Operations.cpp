#include "BusJacker_InternalBUS_Operations.h"

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

void setup_CC_Pins(void)
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

void setup_SREG_pins(void)
{
    pinMode(ShiftLoad_DATA_IN, OUTPUT);
    pinMode(DATA_IN, INPUT);
    pinMode(DATA_OUT, OUTPUT);

    digitalWrite(ShiftLoad_DATA_IN, HIGH);
    digitalWrite(DATA_OUT, HIGH);
    clearBUS();
}

void setup_BUSJacker(void)
{
    setup_CC_Pins();
    setup_SREG_pins();

    setZXControl(0xFF);
    setZXAddrLo(0xFF);
    setZXAddrHi(0xFF);
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

void sendCCTick(void)
{
    //digitalWrite(CC_TICK, HIGH);
    //digitalWrite(CC_TICK, LOW);
    
    //delay(20);
    //delayMicroseconds(2);
    
    bitSet(PORTD, CC_TICK);
    bitClear(PORTD, CC_TICK);
}

void sendCCTickToCCAddr(uint8_t CCAddr)
{
    setCC_AddrLines(CCAddr);
    sendCCTick();
}

void setBUS(uint8_t byte)
{
    setCC_AddrLines(CCAddr_SREG_BUS_OUT);
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
        sendCCTick();
        byte <<= 1;
    }
    return;
}

void clearBUS(void)
{
    setBUS(255);
}

void loadDATA_IN_SREG(void)
{
    //digitalWrite(ShiftLoad_DATA_IN, DATA_IN_LOAD);
    bitClear(PORTC,ShiftLoad_DATA_IN-14);
    sendCCTickToCCAddr(CCAddr_SREG_BUS_IN);

    // DEBUG
    //Serial.print("  loadDATA_IN_SREG");
}

void setDATA_IN_Shift(void)
{
    //digitalWrite(ShiftLoad_DATA_IN, DATA_IN_SHIFT);
    bitSet(PORTC,ShiftLoad_DATA_IN-14);

    // DEBUG
    //Serial.print("  setDATA_IN_Shift");
}

uint8_t getBUS(void)
{
    // Load the ShiftReg
    loadDATA_IN_SREG();

    // Read in the ShiftReg
    setCC_AddrLines(CCAddr_SREG_BUS_IN);
    setDATA_IN_Shift();
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++)
    {
        byte <<= 1;
        byte |= digitalRead(DATA_IN);
        sendCCTick();
    }
    // DEBUG
    //Serial.print("  getBus: ");
    //Serial.print(byte);

    loadDATA_IN_SREG();
    return byte;
}

void setZXControl(uint8_t byte)
{
    setBUS(byte);
    sendCCTickToCCAddr(CCAddr_ZX_ADDR_CONTROL);

    if (consoleDEBUG)
    {
        Serial.print("\nZX_Control: ");
        displayByte(byte);
    }
}

void setZXAddrLo(uint8_t loByte)
{
    setBUS(loByte);
    sendCCTickToCCAddr(CCAddr_ZX_ADDR_HI);

    if (consoleDEBUG)
    {
        Serial.print("\nZX_AddrLo: ");
        displayByte(loByte);
    }
}

void setZXAddrHi(uint8_t hiByte)
{
    setBUS(hiByte);
    sendCCTickToCCAddr(CCAddr_ZX_ADDR_LO);

    if (consoleDEBUG)
    {
        Serial.print("\nZX_AddrHi: ");
        displayByte(hiByte);
    }
}

void pulseAccessZXDataBus(void)
{
    sendCCTickToCCAddr(CCAddr_ZX_DATABUS);
}
