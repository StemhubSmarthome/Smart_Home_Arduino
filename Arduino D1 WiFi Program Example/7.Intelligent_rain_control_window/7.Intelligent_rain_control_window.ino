#include <Servo.h>
#include <D1PinMap.h>

int RaindropAnalogValue;
int RaindropDigitalValue;

D1PinMap pin7(7);
D1PinMap pin3(3);

Servo servo_3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo_3.attach(pin3.getPin());
  pinMode(A0, INPUT);
  pinMode(pin7.getPin(), INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  RaindropAnalogValue = analogRead(A0);
  RaindropDigitalValue = digitalRead(pin7.getPin());
  Serial.print("Raindrop Analog Data: ");
  Serial.println(RaindropAnalogValue);
  Serial.print("Raindrop Digital Data: ");
  Serial.println(RaindropDigitalValue);
  if(RaindropDigitalValue == 0)
  {
    servo_3.write(90);
  }
  else
  {
    servo_3.write(0);
  }
  delay(200);
}
