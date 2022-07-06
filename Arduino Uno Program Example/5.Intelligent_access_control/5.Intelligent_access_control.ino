#include <EM_TTP229.h>
#include <Servo.h>


EM_TTP229 mTTP229;
int SCLPin = A5, SDOPin = A4;

String Read_Key()
{
  String key_name = mTTP229.GetKeyMap();
  char * result = (char *) key_name.c_str();
  return result;
}

String item;
volatile int number;
String password[] = {"", "", ""};

Servo servo_3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  number = 0;
  item = "";
  mTTP229.initTTP229(SCLPin, SDOPin);
  servo_3.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  item = Read_Key();
  if(item != "" && number == 0)
  {
    Serial.print(item);
    password[(int)(0)] = item;
    number = 1;
    delay(250);
  }
  else
  if(item != "" && number == 1)
  {
    Serial.print(item);
    password[(int)(1)] = item;
    number = 2;
    delay(250);
  }
  else
  if(item != "" && number == 2)
  {
    Serial.print(item);
    password[(int)(2)] = item;
    number = 0;
    delay(250);
  }

  if(password[(int)(0)] != "" && password[(int)(1)] != "" && password[(int)(2)] != "")
  {
    if(password[(int)(0)] == "1" && password[(int)(1)] == "2" && password[(int)(2)] == "3")
    {
      servo_3.write(180);
      Serial.println("hello");
      delay(100);
      password[(int)(0)] = "";
      password[(int)(1)] = "";
      password[(int)(2)] = "";
      
    }
    else
    {
      servo_3.write(90);
      Serial.println("Wrong");
      //delay(100);
      password[(int)(0)] = "";
      password[(int)(1)] = "";
      password[(int)(2)] = "";
      
    }
  }
}
