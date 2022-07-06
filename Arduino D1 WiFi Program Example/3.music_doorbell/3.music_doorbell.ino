#include <D1PinMap.h>
#include <Buzzer.h>

D1PinMap pin3(3, INPUT);
D1PinMap pin4(4, OUTPUT);
Buzzer buzzer(pin4.getPin());

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pin3.getPin()) == HIGH)
  {
    buzzer.bendTone(1500, 2500, 1.05, 20, 8);
    buzzer.bendTone(2499, 1500, 1.05, 25, 8);
  }
  else
  {
    digitalWrite(buzzer.getPin(), LOW);
  }
}
