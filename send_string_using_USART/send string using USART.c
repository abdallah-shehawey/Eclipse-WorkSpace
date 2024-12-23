/*
 * send_string_using_USART.c
 *
 * Created: 10/6/2019 1:17:39 PM
 *  Author: Mohamed Zaghlol
 */ 



#define F_CPU 8000000UL
#include <util/delay.h>
#include "USART_interface.h"
#include "STD_MACROS.h"
#include "STD_TYPES.h"
int main(void)
{
	USART_vInit();
	_delay_ms(300);  //because othe uC is initialize LCD waiting 150 ms
	//when i send when LCD is initialize some char will not disblay on LCD
	USART_u8SendStringSynch("Mohamed");
    while(1)
    {
      
    }
}
