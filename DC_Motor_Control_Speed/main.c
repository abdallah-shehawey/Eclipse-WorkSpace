/*
 * main.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Mega
 */

#include "STD_MACROS.h"
#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "TIMER_interface.h"

void main()
{
	DIO_enumSetPinDir(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
	TIMER0_vInit();
	{

	}
}

