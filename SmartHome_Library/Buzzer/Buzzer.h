#ifndef _Buzzer_H_
#define _Buzzer_H_

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#define P9 3
#define D3 3
#define P10 4
#define D4 4
#define P11 5
#define D5 5
#define P12 6
#define D6 6

#define P8 8
#define P7 A4
#define P6 A1
#define P5 A0

#define P1 A3
#define P2 A2
#define P3 A1
#define P4 A0





class Buzzer
{
  public:
  Buzzer(uint8_t pinA);

  uint8_t getPin(void);

  void bendTone(float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);

  void _tone (float noteFrequency, long noteDuration, int silentDuration);

  void tone(uint16_t frequency, uint32_t duration);

  
  protected:
  
  uint8_t pin;

};

#endif
