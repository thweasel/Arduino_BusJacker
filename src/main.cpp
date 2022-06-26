#include <Arduino.h>

#include "BusJacker_Z80_Operations.h"



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

  // testBitPossition();

  // testSREGLoopback();

  // testMemoryWriteSequence();

  // joker();

  while(1){
  sendCCPulse();
  }
  fujiWrite();
  testReadMemory();

  Serial.print("\n- - - - - -");
  delay(1000);
}