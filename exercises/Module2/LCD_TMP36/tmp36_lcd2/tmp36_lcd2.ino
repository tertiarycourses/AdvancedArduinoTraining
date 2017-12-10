#include <LiquidCrystal.h>
#define LED  7 
// the middle TMP36 is connected to A0
const int temperaturePin = A0;


LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Temperature");
  lcd.setCursor(0,1);
  lcd.print("Monitoring");
  pinMode(LED,OUTPUT);
  
  
  
}


void loop()
{
  
 float voltage, degreesC, degreesF;

  

  voltage = getVoltage(temperaturePin);
  
  // Now we'll convert the voltage to degrees Celsius.
  // This formula comes from the temperature sensor datasheet:

  degreesC = (voltage - 0.5) * 100.0;
  
  // While we're at it, let's convert degrees Celsius to Fahrenheit.
  // This is the classic C to F conversion formula:
  
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp Celsius");
  lcd.setCursor(0,1);
  lcd.print(degreesC);

  if (degreesC > 31) {
    digitalWrite(LED,1);
    delay(1000);
    digitalWrite(LED,0);
  }

   
  delay(1000); // repeat once per second (change as you wish!)
}


float getVoltage(int pin)
{
  
  
  return (analogRead(pin) * 0.004882814);
  
  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
}


