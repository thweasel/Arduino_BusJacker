#include <Arduino.h> // Microcontroller dependent

// Defs for Clock Control
#define CC_PORT PORTD
#define CC_A0 7
#define CC_A1 6
#define CC_A2 5
#define CC_TICK 4

#define CCAddr_MASK B00011111
#define CCAddr_SREG_BUS_OUT     0
#define CCAddr_SREG_BUS_IN      1
#define CCAddr_ZX_ADDR_HI       2
#define CCAddr_ZX_ADDR_LO       3
#define CCAddr_ZX_ADDR_CONTROL  4
#define CCAddr_ZX_DATABUS       5

// void setup_CC_Pins(void);    // HIDDEN

// Defs for SREG access
#define ShiftLoad_DATA_IN 14
#define DATA_IN 15
#define DATA_OUT 16

#define DATA_IN_LOAD 0
#define DATA_IN_SHIFT 1

void displayByte(uint8_t byte);

// void setup_SREG_pins (void); // HIDDEN

// CALL THIS IN SETUP
void setup_BUSJacker(void);                  // API

// Clock Control Methods
void setCC_AddrLines(uint8_t CCAddr);       // HIDE?
void sendCCTick(void);                      // HIDE?
void sendCCTickToCCAddr(uint8_t CCAddr);    // HIDE?

// BUS write Methods
void setSregOut(uint8_t byte);              // API
void clearSregOut(void);                    // API -- HIDE?

// BUS read Methods
void loadSregIn(void);            // HIDE?
uint8_t getDataFromSregIn(void);            // HIDE?
uint8_t getSregInData(void);                   // API

// ZX Register Methods

void setZXControl(uint8_t byte);        // API
void setZXAddrLo(uint8_t loByte);       // API
void setZXAddrHi(uint8_t hiByte);       // API
void sendCCTickToZXDatabus(void);        // API

