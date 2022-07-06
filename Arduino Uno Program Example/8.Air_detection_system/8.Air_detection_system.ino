#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dhtA0(A0, 11);


void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  dhtA0.begin();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.backlight();
  lcd.print("");
  lcd.setCursor(0,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(String("T:") + String(dhtA0.readTemperature()));
  lcd.setCursor(0,1);
  lcd.print(String("H:") + String(dhtA0.readHumidity()));

  if(dhtA0.readTemperature() > 26 || dhtA0.readHumidity() > 46)
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}
