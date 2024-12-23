/*
 * Main.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Mega
 */
#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#include "DIO_interface.h"
#include "USART_interface.h"

void main(void)
{
	USART_vInit();

	while (1)
	{
		USART_u8SendStringSynch("ABDaLLah");
		_delay_ms(1000);
		USART_u8SendData(0x0D);
		USART_u8SendStringSynch("ABDaLLah");
	}
}
