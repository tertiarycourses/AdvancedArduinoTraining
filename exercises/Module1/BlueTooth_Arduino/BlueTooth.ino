


int x = 0;
#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Genotronex(10, 11); // RX, TX
int ledpin=13; // led on D2 will show blink on / off
int BluetoothData; // the data given from Computer

void setup() {
  
  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On -> 0: turn off , 1 : turn on , 2 : toggle  ");
  pinMode(ledpin,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
   if (Genotronex.available()){
BluetoothData=Genotronex.read();
   if(BluetoothData=='2'){   // if number 1 pressed ....
    Genotronex.println("toggle! ");
   while (x <10){
   digitalWrite(ledpin,1);
   delay(100);
   digitalWrite(ledpin,0);
   delay(100);
   x++;
   }
   digitalWrite(ledpin,0);
   x = 0;
  
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
  
   Genotronex.println("Off ! ");

  }

  if (BluetoothData=='1'){// if number 0 pressed ....
  digitalWrite(ledpin,1);
  
   Genotronex.println("On ! ");
  }
}
delay(100);// prepare for next data ...
}
