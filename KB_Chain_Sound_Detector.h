#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>

/**************************************************************************
    I2C ADDRESS
**************************************************************************/
#define KB_SD_DEFAULT_ADDRESS	(0x48) //Default address
#define KB_SD_READ_ADDRESS		(0xA1) //Read I2C
/*************************************************************************/

class KB_SD
{
	private:
		
	public:
		uint8_t kb_sd_address = KB_SD_DEFAULT_ADDRESS;

		void begin(void);
		void begin(uint8_t x, uint8_t y);

		void set_address(uint8_t get_Addr); // you can choose address 0x48 or 0x49 
        int read(void);
};