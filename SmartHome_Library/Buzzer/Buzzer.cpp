#include "Buzzer.h"

void Buzzer::bendTone(float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration)
{
  if(silentDuration==0){silentDuration=1;}

  if(initFrequency < finalFrequency)
  {
      for (int i=initFrequency; i<finalFrequency; i=i*prop) {
          _tone(i, noteDuration, silentDuration);
      }

  } else{

      for (int i=initFrequency; i>finalFrequency; i=i/prop) {
          _tone(i, noteDuration, silentDuration);
      }
  }
}

void Buzzer::_tone (float noteFrequency, long noteDuration, int silentDuration)
{

    // tone(10,261,500);
    // delay(500);

      if(silentDuration==0){silentDuration=1;}

      tone(noteFrequency, noteDuration);
      delay(noteDuration);       //milliseconds to microseconds
      //noTone(PIN_Buzzer);
      delay(silentDuration);
}


void Buzzer::tone(uint16_t frequency, uint32_t duration)
{
  
  int period = 1000000L / frequency;
  int pulse = period / 2;
  
  for (long i = 0; i < duration * 1000L; i += period)
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(pin, LOW);
    delayMicroseconds(pulse);
    
  }
}

Buzzer::Buzzer(uint8_t pinA)
{
  pin = pinA;
}


uint8_t Buzzer::getPin(void)
{
  return(pin);
}
