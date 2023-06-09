/*
  getStatus.ino - Simple test for Plantation variable reading
  Created by A.Gordillo-Guerrero, May, 2021.
  Released into the public domain.
*/
#include <GreenGrowEx.h>


/// IMPORTANT HARDWARE DEFINITIONS
// Pin definitions
#if defined(ESP8266)
#pragma message "Compiling for ESP8266 with DHT11 shield..."

// Arduino NodeMCU pin mapping
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
/*
#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)
#define SD3 10 // GPIO10
#define SD2 9  // GPIO09
#define SD1 8 // GPIO08
*/

// Defined pin for DHT11 Wemos Shield
int DHTPin=D4;

#elif defined(ESP32)
#pragma message "Compiling for ESP32..."
int DHTPin=12;

#else
#pragma message "Not compiling for ESP8266 nor ESP32..."
#error "This ain't a ESP8266 nor a ESP32, DHT11 WemosShield. Exiting..."
int DHTPin=12;

#endif

uint8_t buttonPin  = 27; // capacitive button pin
uint8_t relayPin   = 18;
uint8_t oneWirePin = 12;


// Define JackVan object
Plantation Plantation1(DHTPin, buttonPin, relayPin, oneWirePin);


void setup()
{
  Plantation1.init();
}

void loop()
{
  Plantation1.readandcheckAll();
  Plantation1.getStatus();

  delay(3000);

}
