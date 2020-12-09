// defines pins numbers
const int buzzer  = 8;
const int trigPin = 11;
const int echoPin = 12;

// defines variables
long duration;
int distance;

void setup() {
  pinMode(buzzer, OUTPUT);              // Sets the buzzer as an Output
  pinMode(trigPin, OUTPUT);             // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);              // Sets the echoPin as an Input
  Serial.begin(9600);                   // Starts the serial communication
}

void loop() {
           
  digitalWrite(trigPin, LOW);           // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);          // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);    // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;      // Calculating the distance
  
  Serial.print("Distance: ");           // Prints the distance on the Serial Monitor
  Serial.println(distance);

  if(distance >7){
    noTone;
    Serial.print("Distance: ");           // Prints the distance on the Serial Monitor
    Serial.println(distance);
  }
  if(distance <=7 && distance >5){        // If the distance less and equal to 7 and the distance greater than 5  
    tone(buzzer,1000,200);
    delay(700);
    Serial.print("Distance: ");           
    Serial.println(distance);
  }
  if(distance <=5 && distance >3){        // If the distance less and equal to 5 and the distance greater than 3
    tone(buzzer,1000,100);
    delay(400);
    Serial.print("Distance: ");           
    Serial.println(distance);
  }
   if(distance <=3){                      // If the distance less and equal to 3
    tone(buzzer,1000,100);
    Serial.print("Distance: ");          
    Serial.println(distance);
  }
}