/*

 * interrupt_in_CTC_mode.c
 *
 * Created: 9/25/2019 7:19:20 PM
 *  Author: 
Mohamed Zaghlol
 */ 



#include "timer.h"
#include "LED.h"
#include <avr/interrupt.h>
volatile unsigned char counter1=0;
volatile unsigned char counter2=0;
volatile unsigned short counter3=0;
int main(void)
{
	timer_CTC_init_interrupt();
	LED_vInit('A',0);
	LED_vInit('A',1);
	LED_vInit('A',2);
	while (1)
	{
		if (counter1 >= 100)
		{
			LED_vToggle('A', 0);
			counter1 = 0;
		}
		if (counter2 >= 200)
		{
			LED_vToggle('A', 1);
			counter2 = 0;
		}
		if (counter3 >= 300)
		{
			LED_vToggle('A', 2);
			counter3=0;
		}
	}
}


ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}
