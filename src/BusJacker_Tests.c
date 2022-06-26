#include "BusJacker_Z80_Operations.h"
#include <Arduino.h>

void testInternalBUS(void)
{
  Serial.print("\n testInternalBUS 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setSregBus_Out(i);
    loadAndGetDataFromSregBus_In();
    delay(500);
  }

  delay(1000);
  clearSregBus_Out();
  delay(1000);
}

void testZXControl(void)
{
  Serial.print("\n testZXControl 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setRegControlLines_Out(i);
    delay(500);
  }
  delay(1000);
  setRegControlLines_Out(0);
  delay(1000);
  return;
}

void testZXAddrLo(void)
{
  Serial.print("\n testZXAddrLo 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setRegAddrLo_Out(i);
    delay(500);
  }
  delay(1000);
  setRegAddrLo_Out(0);
  delay(1000);
  return;
}

void testZXAddrHi(void)
{
  Serial.print("\n testZXAddrHi 0>1>2>3>4>5>6>7");
  for (int i = 1; i < 255; i = i * 2)
  {
    setRegAddrHi_Out(i);
    delay(500);
  }
  delay(1000);
  setRegAddrHi_Out(0);
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
    setSregBus_Out(c);
    delay(2);
  }
  else
  {
    // c = shiftIn(SRegBus_In_Data_Pin, CLOCK, MSBFIRST);
    Serial.print("\nReadBUS ");
    c = loadAndGetDataFromSregBus_In();
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
  writeByteToHostMemory(0xFF00, 0xF0);
  delay(500);
  writeByteToHostMemory(0x00FF, 0x0F);
  delay(500);
}

void joker(void)
{
  writeByteToHostMemory(23295 - 32, B00010000);
  writeByteToHostMemory(23294, B00010000);
  writeByteToHostMemory(23293, B00010000);
  writeByteToHostMemory(23292, B00010000);
  writeByteToHostMemory(23291 - 32, B00010000);

  writeByteToHostMemory(23294 - 96, B00001000);
  writeByteToHostMemory(23292 - 96, B00001000);

  writeByteToHostMemory(23295 - 128, B00100000);
  writeByteToHostMemory(23294 - 160, B00100000);
  writeByteToHostMemory(23293 - 160, B00100000);
  writeByteToHostMemory(23292 - 160, B00100000);
  writeByteToHostMemory(23291 - 128, B00100000);
}

void testReadMemory()
{
  uint16_t address = 53184;
  uint16_t bytes = 10; // 16384;
  uint8_t aByte;

  for (uint16_t i = address; i < (address + bytes); i++)
  {
    aByte = readByteFromHostMemory(i);
    Serial.print("\n memoryRead: ");
    Serial.print(i);
    Serial.print(" - ");
    Serial.print(aByte);
    Serial.print(" - ");
    Serial.print((char)aByte);
  }
}

void fujiWrite(void)
{
  writeByteToHostMemory(53184, 'F');
  writeByteToHostMemory(53185, 'U');
  writeByteToHostMemory(53186, 'J');
  writeByteToHostMemory(53187, 'I');
  writeByteToHostMemory(53188, 'N');
  writeByteToHostMemory(53189, 'E');
  writeByteToHostMemory(53190, 'T');
}