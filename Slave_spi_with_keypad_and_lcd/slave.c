/*
 * slave.c
 *
 * Created: 10/31/2019 1:32:10 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "LCD.h"
#define F_CPU 8000000UL
#define DUMMY_DATA 0XFF
#include "std_macros.h"
unsigned char error;
int main(void)
{

	unsigned char x;
	SPI_vInit();
	LCD_vInit();
	CLR_BIT(DDRD, 7);
	SET_BIT(DDRD, 6);
	CLR_BIT(DDRD, 5);
	CLR_BIT(DDRD, 4);
	while(1)
	{
		error = SPI_u8Tranceive(DUMMY_DATA, &x);
		if (error == 0)
		{
			LCD_vSend_char(x);
		}
	}
}
