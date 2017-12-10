// The master has an address of 8

#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  Serial.println("I am a Master Arduino");
  
}

byte x = 0;

void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  //Wire.write("x = ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Serial.println(x);
  Wire.endTransmission();    // stop transmitting

  x++;
  if(x > 5 ) x = 0;
  delay(500);
}



