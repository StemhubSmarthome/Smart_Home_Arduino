#include <Servo.h>

volatile int _light;
Servo servo_3;


void setup() {
  // put your setup code here, to run once:
  _light = 0;
  servo_3.attach(3);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  _light = analogRead(A0);
  Serial.println(_light);
  delay(500);
  if(_light > 500)
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
