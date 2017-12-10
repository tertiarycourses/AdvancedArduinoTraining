int led1 = 13;
int led2 = 9;

char ledState ;
void setup() {
  // set the pinmode for the led and button
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
Serial.begin(9600);
  

}

void loop() {


   if (Serial.available()) 
   { // If data is available to read,
     ledState = Serial.read(); // read it and store it in val
   }
   
if(ledState == '1'){
  Serial.println("toggle");

digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
delay(100);
 

}
else if (ledState == '0')  {
  Serial.println("high");
digitalWrite(led1, HIGH);
 delay(100);
digitalWrite(led1, LOW);
 

}

}
