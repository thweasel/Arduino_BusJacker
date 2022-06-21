#include <Arduino.h> // Microcontroller dependent

// Defs for Clock Control
// Port and Pins
#define CC_PORT PORTD
#define CC_A0 7
#define CC_A1 6
#define CC_A2 5
#define CC_TICK 4

// Clock Control Address table
#define CCAddr_MASK B00011111
#define CCAddr_SRegBus_Out          0
#define CCAddr_SRegBus_In           1
#define CCAddr_RegAddrHi_Out        2
#define CCAddr_RegAddrLo_Out        3
#define CCAddr_RegControlLines_Out  4
#define CCAddr_HostSystem           5

// void setupClockControlPins(void);    // HIDDEN

// Defs for SREG access
#define ShiftLoad_DATA_IN 14
#define DATA_IN 15
#define DATA_OUT 16

#define DATA_IN_LOAD 0
#define DATA_IN_SHIFT 1

void displayByte(uint8_t byte);

// void setupSregBusPins (void); // HIDDEN

// CALL THIS IN SETUP
void setup_BUSJacker(void);                  // API

// Clock Control Methods
void setCC_AddrLines(uint8_t CCAddr);       // HIDE?
void sendCCPulse(void);                      // HIDE?
void sendCCPulseToCCAddr(uint8_t CCAddr);    // HIDE?

// BUS write Methods
void setSregBus_Out(uint8_t byte);              // API
void clearSregBus_Out(void);                    // API -- HIDE?

// BUS read Methods
void loadSregBus_In(void);            // HIDE?
uint8_t getDataFromSregBus_In(void);            // HIDE?
uint8_t loadAndGetDataFromSregBus_In(void);                   // API

// ZX Register Methods

void setRegControlLines_Out(uint8_t byte);        // API
void setRegAddrLo_Out(uint8_t loByte);       // API
void setRegAddrHi_Out(uint8_t hiByte);       // API
void sendCCPulseToHostSystem(void);        // API

