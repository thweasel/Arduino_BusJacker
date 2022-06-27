#include <Arduino.h>

#include "BusJacker_Z80_Operations.h"

#include "BusJacker_Tests.h"



void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  setup_BUSJacker();

  // testBitPossition();
}


void readPort()
{
  bitSet(PORTD, CC_Pulse);
  uint8_t portByte = 0;

  while (1)
  {
    bitClear(PORTD, CC_Pulse);
    portByte = PORTB;
    portByte = PORTC;
    bitSet(PORTD, CC_Pulse);
    delayMicroseconds(10);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:

  // testBitPossition();

  // testSREGLoopback();

  // testMemoryWriteSequence();

  // joker();

  readPort();

  while (1)
  {
    sendCCPulse();
  }
  // fujiWrite();
  // testReadMemory();

  Serial.print("\n- - - - - -");
  delay(1000);
}