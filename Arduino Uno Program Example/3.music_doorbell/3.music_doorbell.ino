#include <PH20Port.h>
#include <Buzzer.h>

PH20Port button(P9);
Buzzer buzzer(P10);

void setup() {
  // put your setup code here, to run once:
  pinMode(button.getPin(),INPUT);
  pinMode(buzzer.getPin(),OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(button.getPin())==HIGH) 
  {
    buzzer.bendTone(1500, 2500, 1.05, 20, 8);
    buzzer.bendTone(2499, 1500, 1.05, 25, 8);
  } 
  else 
  {
    digitalWrite(buzzer.getPin(), LOW);
  }

}
