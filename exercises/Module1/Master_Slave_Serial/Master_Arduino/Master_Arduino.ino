
#include <SoftwareSerial.h>
#define SSerialRX 12
#define SSerialTX 11
#define Pin13LED  13
SoftwareSerial mySerial(SSerialRX, SSerialTX); // RX, TX
int byteReceived;
int byteSend;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  // Start the built-in serial port, probably to Serial Monitor
  Serial.begin(9600);
  Serial.println("The Master Arduino");
  Serial.println("Use Serial Monitor, type in upper window, ENTER");
  pinMode(Pin13LED, OUTPUT);    
  
  // Start the software serial port, to another device
  mySerial.begin(4800);   // set the data rate 

} 


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  digitalWrite(Pin13LED, HIGH);  // Show activity
  if (Serial.available())
  {
    char cbyteReceived;
    byteReceived = Serial.read();
    cbyteReceived = byteReceived;
    mySerial.write(cbyteReceived);  // Send byte to Remote Arduino
    Serial.print(("%c",cbyteReceived));
    digitalWrite(Pin13LED, LOW);  // Show activity    
    delay(25);
  }
  
  if (mySerial.available())  //Look for data from other Arduino through the digital pins
   {
    char cbyteSend;
    digitalWrite(Pin13LED, HIGH);  // Show activity
    byteSend = mySerial.read();    // Read received byte
    Serial.write(byteSend);        // Show on Serial Monitor
    Serial.print(("%c",cbyteSend));
    delay(10);
    digitalWrite(Pin13LED, LOW);  // Show activity   
   }  

}


