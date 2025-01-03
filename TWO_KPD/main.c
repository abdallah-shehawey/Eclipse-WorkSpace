/*
 * main.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Mega
 */

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#include "KPD1_interface.h"
#include "KPD2_interface.h"
#include "CLCD_interface.h"

#include <util/delay.h>
u8 press1 , press2;

int main()
{
	CLCD_vInit();
	KPD1_vInit();
	KPD2_vInit();

	while(1)
	{
		do
		{
			press1 = KPD1_u8GetPressed();
			press2 = KPD2_u8GetPressed();
		}while(press1 == NOTPRESSED && press2 == NOTPRESSED);

		if (press1 != NOTPRESSED)
		{
			CLCD_vSendData(press1);
		}
		else if (press2 != NOTPRESSED)
		{
			CLCD_vSendData(press2);
		}
	}
}

