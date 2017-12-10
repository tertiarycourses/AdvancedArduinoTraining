  #include <SoftwareSerial.h>
  #include <Servo.h> 

  SoftwareSerial Genotronex(10, 11);
   int BluetoothData;  
    int servoPin = 9;
     
    Servo servo;  
     
    int angle = 0;   // servo position in degrees 
     
    void setup() 
    { 
      Genotronex.begin(9600);
      Genotronex.println("");
      Genotronex.println("Press 1  -> counterwise : Press 2 : anticlockeise  , Press 3  :stop servoc  ");
      servo.attach(servoPin); 
    } 
     
     
    void loop() 
    { 

      if (Genotronex.available()){

      BluetoothData = Genotronex.read();
      
      // scan from 0 to 180 degrees
      if (BluetoothData == '1'){
      for(angle = 0; angle < 180; angle++)  
      {                                  
        servo.write(angle);               
        delay(15);                   
      } 
       
      }
      
      // now scan back from 180 to 0 degrees
      if (BluetoothData == '2'){
      
      for(angle = 180; angle > 0; angle--)    
      {                                
        servo.write(angle);           
        delay(15);       
      }
    
      }


      
      } 
    } 
