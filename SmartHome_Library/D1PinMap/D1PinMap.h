#ifndef _D1PinMap_H_
#define _D1PinMap_H_

#include <Arduino.h>
#include <stdint.h>
#include <stdlib.h>



class D1PinMap
{
 public:
  D1PinMap(uint8_t pinA);
  
  D1PinMap(uint8_t pinA, uint8_t Mode);

  uint8_t getPin();
  
 protected:
  
  uint8_t pin;
  
  
};




#endif
