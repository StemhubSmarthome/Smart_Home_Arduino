#include <Servo.h>
#include <D1PinMap.h>

volatile int light;
Servo servo_3;
D1PinMap pin3(3);

void setup() {
  // put your setup code here, to run once:
  light = 0;
  servo_3.attach(pin3.getPin());
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  light = analogRead(A0);
  Serial.println(light);
  delay(500);
  if(light > 500)
  {
    servo_3.write(90);
    delay(20);
  }
  else
  {
    servo_3.write(0);
    delay(20);
  }
}
