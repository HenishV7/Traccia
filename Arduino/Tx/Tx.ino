#include <RCSwitch.h>

int ncheck = 1000;

int button_check;
int x = 0;
unsigned long starttime;
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(12);
  pinMode(10,OUTPUT);
  
}

void loop() {
  button_check = analogRead(A1);

  if (button_check > 1000) {
    if (x == 0) {
      starttime = millis();
      x = 1;
    }
    while ((millis() - starttime) <= 600000) {
      mySwitch.send(ncheck, 24);
      ncheck++;
      delay(200);
      digitalWrite(10,HIGH);
    }
    digitalWrite(10, LOW);

  }else{
    x = 0;
  }
}
