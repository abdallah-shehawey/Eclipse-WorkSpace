/*
 * stepper_motor.c
 *
 * Created: 10/29/2019 9:35:45 AM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
int main(void)
{
	DDRD=0Xff;
    while(1)
    {
        SET_BIT(PORTD,0);
		_delay_ms(2000);
		CLR_BIT(PORTD,0);
		SET_BIT(PORTD,1);
		_delay_ms(2000);
		CLR_BIT(PORTD,1);
		SET_BIT(PORTD,2);
		_delay_ms(2000);
		CLR_BIT(PORTD,2);
		SET_BIT(PORTD,3);
		_delay_ms(2000);
		CLR_BIT(PORTD,3);
    }
}
