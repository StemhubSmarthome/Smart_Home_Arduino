void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(3) == 1)
  {
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(4, LOW);
  }
}
