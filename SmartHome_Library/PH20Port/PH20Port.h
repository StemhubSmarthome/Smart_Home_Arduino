#ifndef _PH20Port_H_
#define _PH20Port_H_

#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>

#define NC (0)

#define SLOT1       (1)
#define SLOT2       (2)
#define SLOT3       (3)
#define SLOT4       (4)
#define SLOT5       (5)
#define SLOT6       (6)

#define SLOT_1  SLOT1
#define SLOT_2  SLOT2
#define SLOT_3  SLOT3
#define SLOT_4  SLOT4
#define SLOT_5  SLOT3
#define SLOT_6  SLOT4


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

#define RJ25_MAX 16

typedef struct
{
  uint8_t s1;
  uint8_t s2;
  uint8_t s3;
  uint8_t s4;
  uint8_t s5;
  uint8_t s6;
} PH20Port_Sig;

extern PH20Port_Sig PH20_Port[RJ25_MAX]; 

class PH20Port
{
public:

 PH20Port(void);
 /*
 * Alternate Constructor which can call your own function to map the PH20Port to arduino port,
 * no pins are used or initialized here, but PWM frequency set to 976 Hz
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
 
 PH20Port(uint8_t pinA);
 /*
  * pin is initialized here
  */

 PH20PortS(uint8_t pinA, uint8_t slotA);
 /*
  * \par Function
  *   getPort
  * \par Description
  *   Get current valid port of current RJ25 object
  * \par Output
  *   None
  * \return
  *   Port bumber from PORT_1 to M2
  * \par Others
  *   None 
  */

  
 uint8_t getPin(void);
 /*
  * To return the related pin for setting up the pinMode
  */

 uint8_t getSlot(void);
 
 /*
  * \par Function
 *   dRead1
 * \par Description
 *   Read the digital input value on slot1 of current RJ25 object's port
 * \param[in]
 *   mode - digital input mode INPUT or INPUT_PULLUP
 * \par Output
 *   None
 * \return
 *   Digital input value
 * \par Others
 *   None 
  */
  bool dRead1(uint8_t mode = INPUT);
 
  /*
  * \par Function
  *   dRead2
  * \par Description
  *   Read the digital input value on slot2 of current RJ25 object's port
  * \param[in]
  *   mode - digital input mode INPUT or INPUT_PULLUP
  * \par Output
  *   None
  * \return
  *   Digital input value
  * \par Others
  *   None
  */
  bool dRead2(uint8_t mode = INPUT);
  bool dRead3(uint8_t mode = INPUT);
  bool dRead4(uint8_t mode = INPUT);
  bool dRead5(uint8_t mode = INPUT);

  /**
 * \par Function
 *   dpRead1
 * \par Description
 *   Read the digital input value on slot1 of current RJ25 object's port, the input
 *   mode set as INPUT_PULLUP.
 * \par Output
 *   None
 * \return
 *   Digital input value
 * \par Others
 *   None
 */
  bool dpRead1(void);

  /**
 * \par Function
 *   dpRead2
 * \par Description
 *   Read the digital input value on slot2 of current RJ25 object's port, the input
 *   mode set as INPUT_PULLUP.
 * \par Output
 *   None
 * \return
 *   Digital input value
 * \par Others
 *   None
 */
  bool dpRead2(void);
  
protected:

 uint8_t s1, s2, s3, s4, s5, s6;
 uint8_t pin;
 uint8_t slot;

};





#endif
