/*
 * DC_Motor_with_L293D.c
 *
 * Created: 10/14/2019 12:01:24 AM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	DDRD=0XFF;
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
	while(1)
	{
		SET_BIT(PORTD,0);
		_delay_ms(2000);
		CLR_BIT(PORTD,0);
		SET_BIT(PORTD, 1);
		_delay_ms(2000);
		CLR_BIT(PORTD, 1);
		SET_BIT(PORTD,5);
		_delay_ms(2000);
		CLR_BIT(PORTD,5);
		SET_BIT(PORTD,4);
		_delay_ms(2000);
		CLR_BIT(PORTD,4);
	}
}


