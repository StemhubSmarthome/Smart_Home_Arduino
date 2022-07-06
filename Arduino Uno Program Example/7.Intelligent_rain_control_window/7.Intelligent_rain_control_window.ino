#include <Servo.h>

#define RaindropAnalogPin A0
#define RaindropDigitalPin 7

int RaindropAnalogValue;
int RaindropDigitalValue;

Servo servo_3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo_3.attach(3);
  pinMode(RaindropAnalogPin, INPUT);
  pinMode(RaindropDigitalPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  RaindropAnalogValue= analogRead(RaindropAnalogPin);
  RaindropDigitalValue= digitalRead(RaindropDigitalPin);
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
