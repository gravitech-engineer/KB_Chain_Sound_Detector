#include <KB_Chain_Sound_Detector.h>

#include <Wire.h>

KB_SD KB;

void setup() {
   KB.begin();        // Join i2c bus
  Serial.begin(9600);  // Start serial for output


}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println( KB.read());
delay(5);
}
