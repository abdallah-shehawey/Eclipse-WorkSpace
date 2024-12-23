/*
 * main.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Mega
 */

#define F_CPU 1000000UL

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#include "CLCD_interface.h"
#include "TIMER_interface.h"
#include "US_interface.h"
#include "DIO_interface.h"


#include <util/delay.h>

u8 distance;
int main()
{
  TIMER1_vInit();
  US_vInit();
  CLCD_vSendString("distance : ");
  while (1)
    {
      distance = US_u8ReadDistance();
      CLCD_vSendData((distance / 10) + 48);
      CLCD_vSendData((distance % 10) + 48);
      CLCD_vSetPosition(1, 12);
    }
}

