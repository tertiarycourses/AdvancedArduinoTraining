

#include <SoftwareSerial.h>
SoftwareSerial Genotronex(12, 11); // TX of HC05 -- D12 of Ard , RX of HC05 to D11
int BT ;  
//L293D
//Motor A
const int motorPin1  = 5;  // Pin 7 of L293
const int motorPin2  = 6;  // Pin 2 of L293
//Motor B
const int motorPin3  = 10; // Pin  15 of L293
const int motorPin4  = 9;  // Pin  10 of L293

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    
    //Serial.begin(9600);
    
    Genotronex.begin(9600);
    
    Genotronex.print("Press 1,2,3,4,0");
//    Genotronex.println("Press 2 : Motor A anticlockeise " );    
//    Genotronex.println("Press 3  -> Motor B counterwise ");
//    Genotronex.println("Press 4 : Motor B anticlockeise");
//   Genotronex.println("Press 0  :stop Motor  ");
//
//    
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    
    

    
    
    
}


void loop(){



   if (Genotronex.available()){

   BT  = Genotronex.read();
      
   
  


    if ( BT  == '0') 
    {
      Stop_Motor();
    }


  if ( BT  == '1') 
    {
      Serial.print("clockwise");
      Motor_A_Clockwise();
    }

    if ( BT  == '2') 
    {
      Motor_A_AntiClockwise();
      
    }

    if ( BT  == '3') 
    {

      Motor_B_Clockwise();
    }

    if ( BT  == '4') 
    {
      Motor_B_AntiClockwise();
    }

   }

}


void Motor_A_Clockwise(){
  //This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(2000); 
}

void Motor_A_AntiClockwise(){

  //This code will turn Motor A counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(2000);
}

void Motor_B_Clockwise(){

  //This code will turn Motor B clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(2000); 
}


void Motor_B_AntiClockwise(){
  //This code will turn Motor B counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(2000);    
}

void Stop_Motor(){

  //And this code will stop motors
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  
}

