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
    
    Serial.begin(9600);
    
    
    
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    
    

    
    
    
}


void loop(){


  Serial.println("1:Motor_A_Clockwise , 2: Motor_A_AntiClockwise");
  Serial.println("3 :Motor_B_Clockwise , 4 : Motor_B_AntiClockwise , 0 : Stop_Motor");
  
  while(Serial.available() ==  0);
  int val = Serial.read() - '0';
  Serial.print(" The value you entered is ");
  Serial.println(val);


    if ( val == 0) 
    {
      Stop_Motor();
    }


  if ( val == 1) 
    {
      Serial.print("clockwise");
      Motor_A_Clockwise();
    }

    if ( val == 2) 
    {
      Motor_A_AntiClockwise();
      
    }

    if ( val == 3) 
    {

      Motor_B_Clockwise();
    }

    if ( val == 4) 
    {
      Motor_B_AntiClockwise();
    }
//
//  Motor_A_Clockwise();
//  Motor_A_AntiClockwise();
//  Motor_B_Clockwise();
//  Motor_B_AntiClockwise();
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

