
 
  
/* PIR switch */

const int ledPin = 13 ;
const int inputPin = 10;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin,INPUT);
  digitalWrite(ledPin,LOW);
}


void loop(){
  int val = digitalRead(inputPin);
  if ( val == HIGH)
    {
      Serial.println("Motion detected");
      digitalWrite(ledPin,HIGH);

      delay(500);      
      digitalWrite(ledPin,LOW);
     
       
    }
}

