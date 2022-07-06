#include "PH20Port.h"

PH20Port_Sig PH20_Port[RJ25_MAX] =
{
  { A3, NC, NC, NC, NC, NC },  //1
  { A2, NC, NC, NC, NC, NC },  //2
  { A1, NC, NC, NC, NC, NC },  //3
  { A0, NC, NC, NC, NC, NC },  //4
  {  7, A0, NC, NC, NC, NC },  //5
  {  8, A1, NC, NC, NC, NC },  //6
  { A5, A4, NC, NC, NC, NC },  //7
  {  6,  5, NC, NC, NC, NC },  //8
  {  3, NC, NC, NC, NC, NC },  //9
  {  4, NC, NC, NC, NC, NC },  //10
  {  5, NC, NC, NC, NC, NC },  //11
  {  6, NC, NC, NC, NC, NC },  //12
  {  4,  7,  8, A3, NC, NC },  //13
  {  2,  7, A5, A4, NC, NC },  //14
  { NC, NC,  3,  5,  6, NC },  //15
  { NC, NC, A4, A5,  2, NC },  //16
};

PH20Port::PH20Port(void)
{
  pin = 0;
}

PH20Port::PH20Port(uint8_t pinA)
{
  pin = pinA;
}

PH20Port::PH20PortS(uint8_t pinA, uint8_t slotA)
{
  if (pinA < 1) return;
  s1 = PH20_Port[pinA-1].s1;
  s2 = PH20_Port[pinA-1].s2;
  s3 = PH20_Port[pinA-1].s3;
  s4 = PH20_Port[pinA-1].s4;
  s5 = PH20_Port[pinA-1].s5;
  s6 = PH20_Port[pinA-1].s6;
}


uint8_t PH20Port::getPin(void)
{
  return(pin);
}

uint8_t PH20Port::getSlot(void)
{
  return(slot);
}

bool PH20Port::dRead1(uint8_t mode)
{
  bool val;
  pinMode(s1, mode);
  val = digitalRead(s1);
  return(val);
}

bool PH20Port::dRead2(uint8_t mode)
{
  bool val;
  pinMode(s2, mode);
  val = digitalRead(s2);
  return(val);
}

bool PH20Port::dRead3(uint8_t mode)
{
  bool val;
  pinMode(s3, mode);
  val = digitalRead(s3);
  return(val);
}

bool PH20Port::dRead4(uint8_t mode)
{
  bool val;
  pinMode(s4, mode);
  val = digitalRead(s4);
  return(val);
}

bool PH20Port::dRead5(uint8_t mode)
{
  bool val;
  pinMode(s5, mode);
  val = digitalRead(s5);
  return(val);
}

bool PH20Port::dpRead1(void)
{
  bool val;
  pinMode(s1, INPUT_PULLUP);
  val = digitalRead(s1);
  return(val);
}

bool PH20Port::dpRead2(void)
{
  bool val;
  pinMode(s2, INPUT_PULLUP);
  val = digitalRead(s2);
  return(val);
}
