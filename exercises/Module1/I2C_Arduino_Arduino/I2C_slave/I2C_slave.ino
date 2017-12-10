// The Slave has an address of 8

int LED = 13;
int x = 0;

#include <Wire.h>

void setup() {
   
  pinMode (LED, OUTPUT); // Define the LED pin as Output
  Wire.begin(9);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  Serial.println("I am a slave arduino");
}

void loop() {
  delay(100);
    
}

void receiveEvent(int howMany) {
  while ( Wire.available()> 1) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.println(c);         // print the character
 }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer

  
 
}

