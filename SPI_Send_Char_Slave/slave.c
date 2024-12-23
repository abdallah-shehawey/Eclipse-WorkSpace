/*
 * slave.c
 *
 *  Created on: Sep 9, 2024
 *      Author: Mega
 */


#include "STD_MACROS.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "CLCD_interface.h"

#define DIPPY_Date 0xff

volatile u8 Error_State, KPD_Press;

void main()
{
	CLCD_vInit();
	SPI_vInit();
	while(1)
	{
		Error_State = SPI_u8Tranceive(DIPPY_Date, &KPD_Press);
		if (Error_State == OK)
		{
			CLCD_vSendData(KPD_Press);
		}
	}

}
