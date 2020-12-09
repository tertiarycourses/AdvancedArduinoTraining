void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(5,OUTPUT);
}

void loop() {
  if (digitalRead(2) == LOW) {
    while (1) {
      analogWrite(5,255);
      delay(3000);
      analogWrite(5,80);
      delay(3000);
    }
  }
  else digitalWrite(5, LOW);
}