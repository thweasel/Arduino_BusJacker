#include <Arduino.h>

#include "BusJacker_Z80_Operations.h"

void testInternalBUS(void)
{
  Serial.print("\n testInternalBUS 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setBUS(i);
    getBUS();
    delay(500);
  }

  delay(1000);
  clearBUS();
  delay(1000);
}

void testZXControl(void)
{
  Serial.print("\n testZXControl 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setZXControl(i);
    delay(500);
  }
  delay(1000);
  setZXControl(0);
  delay(1000);
  return;
}

void testZXAddrLo(void)
{
  Serial.print("\n testZXAddrLo 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setZXAddrLo(i);
    delay(500);
  }
  delay(1000);
  setZXAddrLo(0);
  delay(1000);
  return;
}

void testZXAddrHi(void)
{
  Serial.print("\n testZXAddrHi 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setZXAddrHi(i);
    delay(500);
  }
  delay(1000);
  setZXAddrHi(0);
  delay(1000);
  return;
}

void testBitPossition(void)
{
  Serial.print("\nBusTest == START ==");

  testInternalBUS();
  testZXControl();
  testZXAddrLo();
  testZXAddrHi();

  Serial.print("\nBusTest == END ==\n\n");
  return;
}

void testSREGLoopback(void)
{
  uint8_t c = 0;
  Serial.readBytes(&c, 1);
  if (0 != c)
  {
    Serial.print("\nWriteBUS ");
    Serial.print("Output ");
    Serial.print(c);
    Serial.print(" [");
    Serial.print((char)c);
    Serial.print("]");
    setBUS(c);
    delay(2);
  }
  else
  {
    // c = shiftIn(DATA_IN, CLOCK, MSBFIRST);
    Serial.print("\nReadBUS ");
    c = getBUS();
    Serial.print("Input ");
    Serial.print(c);
    Serial.print(" [");
    Serial.print((char)c);
    Serial.print("]");
  }
  c = 0;
}

void testMemoryWriteSequence(void)
{
  writeOneByteToMemory(0xFF00, 0xF0);
  delay(500);
  writeOneByteToMemory(0x00FF, 0x0F);
  delay(500);
}

void joker(void)
{
    writeOneByteToMemory(23295-32,B00010000);
    writeOneByteToMemory(23294,B00010000);
    writeOneByteToMemory(23293,B00010000);
    writeOneByteToMemory(23292,B00010000);
    writeOneByteToMemory(23291-32,B00010000);
    
    writeOneByteToMemory(23294-96,B00001000);
    writeOneByteToMemory(23292-96,B00001000);

    writeOneByteToMemory(23295-128,B00100000);
    writeOneByteToMemory(23294-160,B00100000);
    writeOneByteToMemory(23293-160,B00100000);
    writeOneByteToMemory(23292-160,B00100000);
    writeOneByteToMemory(23291-128,B00100000);
}

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  setup_BUSJacker();

  // testBitPossition();
}


void loop()
{
  // put your main code here, to run repeatedly:
  
  //testBitPossition();

  //testSREGLoopback();

  //testMemoryWriteSequence();
  joker();

  Serial.print("\n- - - - - -");
  delay(500);
}