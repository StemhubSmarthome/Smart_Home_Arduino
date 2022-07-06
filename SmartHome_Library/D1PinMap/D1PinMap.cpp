#include "D1PinMap.h"


D1PinMap::D1PinMap(uint8_t pinA)
{
  if(pinA == D10 || pinA == 10)
  {
    pin = 15;
  }
  else
  if(pinA == D4 || pinA == 4)
  {
    pin = 4;
  }
  else
  if(pinA == D3 || pinA == 3)
  {
    pin = 5;
  }
  else
  if(pinA == D5 || pinA == 5)
  {
    pin = 14;
  }
  else
  if(pinA == D6 || pinA == 6)
  {
    pin = 12;
  }
  else
  if(pinA == D7 || pinA == 7)
  {
    pin = 13;
  }
  else
  if(pinA == D8 || pinA == 8)
  {
    pin = 0;
  }
  else
  {
    pin = pinA;
  }
}

D1PinMap::D1PinMap(uint8_t pinA, uint8_t Mode)
{
  if(pinA == D10 || pinA == 10)
  {
    pin = 15;
    pinMode(pin, Mode);
  }
  else
  if(pinA == D4 || pinA == 4)
  {
    pin = 4;
    pinMode(pin, Mode);
  }
  else
  if(pinA == D3 || pinA == 3)
  {
    pin = 5;
    pinMode(pin, Mode);
  }
  else
  if(pinA == D5 || pinA == 5)
  {
    pin = 14;
    pinMode(pin, Mode);
  }
  else
  if(pinA == D6 || pinA == 6)
  {
    pin = 12;
    pinMode(pin, Mode);
  }
  else
  if(pinA == D7 || pinA == 7)
  {
    pin = 13;
    pinMode(pin, Mode);
  }
  else
  if(pinA == D8 || pinA == 8)
  {
    pin = 0;
    pinMode(pin, Mode);
  }
  else
  {
    pin = pinA;
    pinMode(pin, Mode);
  }
}


 uint8_t D1PinMap::getPin()
{
  return pin;
}
