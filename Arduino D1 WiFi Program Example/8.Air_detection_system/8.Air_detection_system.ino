#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <D1PinMap.h>
D1PinMap pin5(5);
D1PinMap pin6(6);
D1PinMap pin7(7);
DHT dht7(pin7.getPin(), DHT11);

LiquidCrystal_I2C lcd(0x27,16,2);

int count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht7.begin();
  pinMode(pin5.getPin(), OUTPUT);
  pinMode(pin6.getPin(), OUTPUT);
  lcd.begin();
  lcd.backlight();
  lcd.print("");
  lcd.setCursor(0,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(String("T:") + String(dht7.readTemperature()));
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(String("T:") + String(dht7.readTemperature()));
  lcd.setCursor(0,1);
  lcd.print(String("H:") + String(dht7.readHumidity()));
  
  if(dht7.readTemperature() > 26 || dht7.readHumidity() > 56)
  {
    digitalWrite(pin5.getPin(), HIGH);
    digitalWrite(pin6.getPin(), LOW);
  }
  else
  {
    digitalWrite(pin5.getPin(), LOW);
    digitalWrite(pin6.getPin(), LOW);
  }
  delay(200);
}
