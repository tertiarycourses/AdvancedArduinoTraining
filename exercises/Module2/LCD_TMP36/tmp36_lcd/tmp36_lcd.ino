#include <LiquidCrystal.h>

const int pinTemp=A0;
LiquidCrystal lcd(12,11,5,4,3,2);
float tempWaarde;
float temperatuur;
long huidigeTijd=0;
long tijdLimiet=30000;
float temp[30];
float gemTemp;
int teller;
unsigned long vorigeTijd=0;
float som;

void setup() {
  lcd.begin(16,2);
  lcd.print("Temperatuur ");
  
  float initTemp=((analogRead(pinTemp)/1024.0)*5-0.5)*100;
  delay(5);
  lcd.print(initTemp);

  

}

void loop() {
  unsigned long huidigeTijd=millis();
  

  if(huidigeTijd-vorigeTijd<tijdLimiet){
    tempWaarde=(analogRead(pinTemp)/1024.0)*5;
    temperatuur=(tempWaarde-0.5)*100;
    temp[teller]=temperatuur;
    teller++;
    delay(1000);
    
  }
  else{
    for(int i=0;i<30;i++){
      som=som+temp[i];
    }
    gemTemp=som/30;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperatuur ");
    lcd.print(gemTemp);
    lcd.setCursor(0,0);
    som=0;
    vorigeTijd=huidigeTijd;
    for(int i=0;i<30;i++){
      temp[i]=0;
    }
    teller=0;
    
  }

  
  
  
  
  
  
  
  

}
