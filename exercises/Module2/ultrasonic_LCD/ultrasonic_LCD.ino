// Ultrasonic detection

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
#define trigPin 9
#define echoPin 8
#define led 7
#define led2 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
 
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Distance");
  lcd.setCursor(0,1);
  lcd.print("Monitoring");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration, distance;


  
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)* 0.0342 ;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Out of Range");
    Serial.println("Out of range");
    lcd.clear();
    delay(5000);
  }
  else {
   
    lcd.setCursor(0,0);
    lcd.print("distance : ");
    lcd.print(distance);
    lcd.print(" cm");
    
     
    delay(1000);
  }
  delay(500);
}
