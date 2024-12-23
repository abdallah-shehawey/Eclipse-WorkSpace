/*
 * master.c
 *
 * Created: 10/31/2019 1:01:40 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "std_macros.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{

	unsigned char x=0xff , y;
	keypad_vInit();
	SPI_vInit();
	SET_BIT(DDRD, 7);
		CLR_BIT(DDRD, 6);
		SET_BIT(DDRD, 5);
		SET_BIT(DDRD, 4);
    while(1)
    {
       x = keypad_u8check_press();
	   if(x!=0xff)
	   {
		   SPI_u8Tranceive(x, &y);
	   }
	   _delay_ms(250);
    }
}
