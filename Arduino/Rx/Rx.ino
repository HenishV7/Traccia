#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int count = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);
  pinMode(10, OUTPUT);
}

void loop() {
  if (mySwitch.available()) {

    int value = mySwitch.getReceivedValue();

    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print(micros());
      Serial.print(" ");
      Serial.println( mySwitch.getReceivedValue());
      digitalWrite(10, HIGH);
      count = 0;
    }
    mySwitch.resetAvailable();
  }
  else {
    count += 1;
    if (count > 10000) {
      digitalWrite(10, LOW);
    }
  }


}
