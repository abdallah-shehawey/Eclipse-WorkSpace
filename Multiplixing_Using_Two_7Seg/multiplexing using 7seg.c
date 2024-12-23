#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "timer.h"
#include "seven segment.h"
#include "std_macros.h"

volatile unsigned char counter1=0;
volatile unsigned char counter2=0;
volatile unsigned char counter3=0;

int main(void)
{
	seven_seg_vinit('D');
	timer_CTC_init_interrupt();
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	while(1)
	{

		CLR_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		seven_seg_write('D',counter2%10);

		while(counter3==0);   //work ad _delay_ms(10)
		counter3=0;
		CLR_BIT(PORTA,1);
		SET_BIT(PORTA,0);
		seven_seg_write('D',counter2/10);
		while(counter3==0);    //work ad _delay_ms(10)
		counter3=0;

		if(counter1>=100)
		{
			counter1=0;
			counter2++;
		}
	}
}
ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter3=1;
}
