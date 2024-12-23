
/*
 * DC_motors.c
 *
 * Created: 10/13/2019 8:29:45 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	SET_BIT(DDRD,0);
	SET_BIT(DDRD,1);
    while(1)
    {
		SET_BIT(PORTD, 0); // rotate motor clockwise
		_delay_ms(2000);
		CLR_BIT(PORTD, 0); // stop motor
		
		SET_BIT(PORTD, 1); // rotate motor anti-clockwise
		_delay_ms(2000);
		CLR_BIT(PORTD, 1); // stop motor
    }
}
