#include <D1PinMap.h>

D1PinMap pin3(3, INPUT);
D1PinMap pin4(4, OUTPUT);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pin3.getPin()) == 1)
  {
    digitalWrite(pin4.getPin(), HIGH);
  }
  else
  {
    digitalWrite(pin4.getPin(), LOW);
  }
}
