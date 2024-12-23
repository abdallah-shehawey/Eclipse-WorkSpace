/*
 * master.c
 *
 *  Created on: Sep 9, 2024
 *      Author: Mega
 */

#include "STD_MACROS.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "KPD_interface.h"
#include "USART_interface.h"

volatile u8 Error_State, KPD_Press, SPI_Recieve;

void main()
{

	KPD_vInit();
	USART_vInit();
	SPI_vInit();
	while (1)
	{
		Error_State = USART_u8ReceiveData(&KPD_Press);
		if (Error_State == OK)
		{
			SPI_u8Tranceive(KPD_Press, &SPI_Recieve);
		}
	}
}
