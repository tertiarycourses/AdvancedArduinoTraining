boolean ledOn = false;
int button_state = 0;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
 
}

void loop() {
  button_state = digitalRead(2);
  if ( button_state == 1)
  {
    buttonPressed();
  }

  delay(100);
}

void buttonPressed()
{
  if(ledOn)
  {
    ledOn = false;
    digitalWrite(13,LOW);
  }else
  {
    ledOn = true;
    digitalWrite(13,HIGH);
  }
}


