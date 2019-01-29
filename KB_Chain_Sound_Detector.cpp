#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>

#include "KB_Chain_Sound_Detector.h"
/**************************************************************************/
/*
        Sets up the Hardware
*/
/**************************************************************************/
void KB_SD::begin()
{
    Wire.begin(4,5);
}

/**************************************************************************/

void KB_SD::set_address(uint8_t get_Addr) // you can choose address 0x48 or 0x49 
{
	kb_sd_address = get_Addr;
}

int KB_SD::read(void)
{
  uint8_t a, b;
  uint16_t raw;

  Wire.beginTransmission(kb_sd_address);
  Wire.write(KB_SD_READ_ADDRESS);
  Wire.endTransmission(false);
  Wire.requestFrom(kb_sd_address, 2);
  while (Wire.available()) 
  {
    a = Wire.read();
    b = Wire.read();
  }
  
  raw = (a << 8) & 0x3FF;
  raw = b + raw;
 
 return raw;
}