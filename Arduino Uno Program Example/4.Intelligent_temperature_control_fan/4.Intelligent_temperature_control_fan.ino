
#include <DHT.h>

DHT dhtA0(A0, 11);

void setMotor8833(int speedpin,int dirpin, int speed)
{
  if (speed == 0)
  {
    digitalWrite(dirpin, LOW);
    analogWrite(speedpin, LOW);
  }
  else if (speed > 0)
  {
    digitalWrite(dirpin, LOW);
    analogWrite(speedpin, HIGH);
  }
}

void setup(){
  Serial.begin(9600);
   dhtA0.begin();

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void loop(){
  Serial.println(String("T:") + String(dhtA0.readTemperature()));
  delay(500);
  if (dhtA0.readTemperature() > 30) {
    setMotor8833(5, 6, 100);

  } else {
    setMotor8833(5, 6, 0);

  }

}
