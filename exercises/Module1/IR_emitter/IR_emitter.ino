
#include <IRremote.h>
//need to connect to pin 3
IRsend irsend ;

void setup()
{
  Serial.begin(9600);

}

void loop() {
  irsend.sendRC5(0xF61E2A57, 32);
    delay(100);
    irsend.sendRC5(0xF61E2A57, 32);
    delay(100);
    irsend.sendRC5(0xF61E2A57, 32);
    delay(1000);
}
