/*
 * toggle_led_connected_to_portd.c
 *
 * Created: 7/23/2018 3:21:47 PM
 *  Author: Mohamed Zaghlol
 */ 

#include "LED.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
			   
	LED_vInit('D',0);
	while(1)
	{
		LED_vToggle('D',0);
		_delay_ms(1000);
	}
}

