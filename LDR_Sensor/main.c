/*
 * main.c
 *
 *  Created on: Oct 11, 2024
 *      Author: Mega
 */
#include <util/delay.h>

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include "LDR_interface.h"

LDR_Config LDR0 = {ADC_CHANNEL1, 5, ADC_RES_10_BIT};
u16 LDR_Result;

void main()
{
	ADC_vInit();
	CLCD_vInit();
	while(1)
	{
		LDR_u8GetLightPres(&LDR0, &LDR_Result);
		CLCD_vClearScreen();
		CLCD_vSendIntNumber(LDR_Result);
		_delay_ms(50);
	}
}
