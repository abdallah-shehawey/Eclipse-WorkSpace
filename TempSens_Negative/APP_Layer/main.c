/*
 * main.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Mega
 */

#include "STD_MACROS.h"
#include "STD_TYPES.h"

#include "../MCAL/ADC_interface.h"
#include "../MCAL/DIO_interface.h"

#include "../HAL/CLCD_interface.h"
#include "../HAL/LM35_interface.h"



LM35_Config lm350 = {ADC_ADC0_ADC1, 5, ADC_RES_10_BIT};

int main()
{
	u8 temp;
	u16 volt;
	CLCD_vInit();
	ADC_vInit();
	CLCD_vSendString("TEMP = ");
	while (1)
	{
		LM35_u8GetAnalogSignal(&lm350, &volt);
		if (volt >= 1000)
		{
			temp = (volt - 1000)/ 10;

			if (temp < 10)
			{
				CLCD_vSetPosition(1, 8);
				CLCD_vSendData(temp + 48);
				CLCD_vSendData(0xDF);
				CLCD_vSendData('C');
				CLCD_vSendData(' ');
			}
			else if (temp < 100)
			{
				CLCD_vSetPosition(1, 8);
				CLCD_vSendData((temp/10) + 48);
				CLCD_vSendData((temp % 10) + 48);
				CLCD_vSendData(0xDF);
				CLCD_vSendData('C');
			}
		}
		else
		{
			temp = (1000 - volt )/ 10;
			if (temp < 10)
			{
				CLCD_vSetPosition(1, 8);
				CLCD_vSendData('-');
				CLCD_vSendData(temp + 48);
				CLCD_vSendData(0xDF);
				CLCD_vSendData('C');
				CLCD_vSendData(' ');
			}
			else if (temp < 100)
			{
				CLCD_vSetPosition(1, 8);
				CLCD_vSendData('-');
				CLCD_vSendData((temp/10) + 48);
				CLCD_vSendData((temp % 10) + 48);
				CLCD_vSendData(0xDF);
				CLCD_vSendData('C');
			}
		}
	}
}

