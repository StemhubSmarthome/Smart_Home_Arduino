#include <DHT.h>
#include <D1PinMap.h>
D1PinMap pin4(4);
D1PinMap pin5(5);
D1PinMap pin6(6);
DHT dht4(pin4.getPin(), DHT11);

void setMotor8833(int speedpin, int dirpin, int speed)
{
  if(speed == 0)
  {
    digitalWrite(speedpin, LOW);
    digitalWrite(dirpin, LOW);
  }
  else
  if(speed > 0)
  {
    digitalWrite(speedpin, HIGH);
    digitalWrite(dirpin, LOW);
  }
}

void setup(){
  Serial.begin(115200);
  dht4.begin();
  pinMode(pin5.getPin(), OUTPUT);
  pinMode(pin6.getPin(), OUTPUT);
  digitalWrite(pin5.getPin(), LOW);
  digitalWrite(pin6.getPin(), LOW);
}

void loop(){
  Serial.println(String("T:") + String(dht4.readTemperature()));
  delay(500);
  if(dht4.readTemperature() > 26)
  {
    setMotor8833(pin5.getPin(), pin6.getPin(), 100);
  }
  else
  {
    setMotor8833(pin5.getPin(), pin6.getPin(), 0);
  }
  
}
