
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
  Serial.println("Slave Arduino");  // Can be ignored
  pinMode(Pin13LED, OUTPUT);   
  
  // Start the software serial port, to another device
  mySerial.begin(4800);   // set the data rate 
}


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  //Copy input data to output  
  if (mySerial.available()) 
  {
    char cbyteSend;
    byteSend = mySerial.read();   // Read the byte 
    
    digitalWrite(Pin13LED, HIGH);  // Show activity
    delay(25);              
    digitalWrite(Pin13LED, LOW);   

    cbyteSend = byteSend;
   // mySerial.write(cbyteSend); // Send the byte back, not necessary
    Serial.print(("%c",cbyteSend));
    }


  if (Serial.available())
  {
    char cbyteReceived;
    byteReceived = Serial.read();
    cbyteReceived = byteReceived;
    mySerial.write(cbyteReceived);  // Send byte to Remote Arduino
    Serial.print(("%c",cbyteReceived));
    digitalWrite(Pin13LED, HIGH);  // Show activity    
    delay(25);
  }
}
  

