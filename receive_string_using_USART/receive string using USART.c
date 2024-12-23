/*
 * receive_string_using_USART.c
 *
 * Created: 10/6/2019 1:42:17 PM
 *  Author: Mohamed Zaghlol
 */ 

#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "USART_private.h"
#include "USART_interface.h"

#include <util/delay.h>

int main(void)
{
	CLCD_vInit();
	USART_vInit();
	_delay_ms(300);
	char x, y, z = 0xff;
	while(1)
	{
		do
		{
			y = USART_u8ReceiveData(&x);
		}while (y != OK);
		CLCD_vSendData(x);
	}
}

