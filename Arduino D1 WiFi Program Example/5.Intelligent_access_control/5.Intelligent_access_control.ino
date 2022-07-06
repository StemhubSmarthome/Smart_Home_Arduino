#include <EM_TTP229.h>
#include <Servo.h>
#include <D1PinMap.h>

EM_TTP229 mTTP229;
int SCLPin = 5, SDOPin = 4;

Servo servo_10;
D1PinMap pin10(10);

String Read_Key()
{
  String key_name = mTTP229.GetKeyMap();
  char * result = (char *) key_name.c_str();
  return result;
}

String item;
volatile int number;
String password[]={"", "", ""};

void setup() {
  // put your setup code here, to run once:
  item = "";
  number = 0;
  mTTP229.initTTP229(5, 4);
  //Serial.begin(115200);
  servo_10.attach(pin10.getPin());
}

void loop() 
{
  item = Read_Key();
  if(item != "" && number == 0)
  {
    Serial.println(item);
    password[(int)(0)] = item;
    number = 1;
    delay(250);
  }
  else
  if(item != "" && number == 1)
  {
    Serial.println(item);
    password[(int)(1)] = item;
    number = 2;
    delay(250);
  }
  else
  if(item != "" && number == 2)
  {
    Serial.println(item);
    password[(int)(2)] = item;
    number = 0;
    delay(250);
  }

  if(password[(int)(0)] != "" && password[(int)(1)] != "" && password[(int)(2)] != "")
  {
    if(password[(int)(0)] == "1" && password[(int)(1)] == "2" && password[(int)(2)] == "3")
    {
      servo_10.write(90);
      delay(20);
      password[(int)(0)] = "";
      password[(int)(1)] = "";
      password[(int)(2)] = "";
    }
    else
    {
      servo_10.write(180);
      delay(20);
    }
  }
}
