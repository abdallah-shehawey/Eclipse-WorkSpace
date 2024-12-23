/*
 * ICU.c
 *
 * Created: 9/30/2019 12:20:38 AM
 *  Author: Mohamed Zaghlol
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include "util\delay.h"
#include "LCD.h"
#include "timer.h"
#include "std_macros.h"
int main(void)
{

	unsigned short a,b,c,high,period,duty_cycle,frequency;
	LCD_vInit();
	TCCR1A = 0;
	TIFR |= (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */

	TCCR1B = 0xc2;  	/* Rising edge, no prescaler , noise canceler*/
	while (READ_BIT(TIFR, ICF1) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR |= (1<<ICF1);  	/* Clear ICF flag */

	TCCR1B = 0x82;  	/* Falling edge, no prescaler ,noise canceler*/
	while (READ_BIT(TIFR, ICF1) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR |= (1<<ICF1);  	/* Clear ICF flag */

	TCCR1B = 0xc2;  	/* Rising edge, no prescaler ,noise canceler*/
	while (READ_BIT(TIFR, ICF1) == 0);
	c = ICR1;  		/* Take value of capture register */
	TIFR |= (1<<ICF1);  	/* Clear ICF flag */

	TCCR1B = 0;  		/* Stop the timer */

		if(a<b && b<c)  	/* Check for valid condition,
					          to avoid timer overflow reading */
		{
			high=b-a;
			period=c-a;
			duty_cycle=((float)high/period)*100;
			frequency=F_CPU/(period * 8ul) ;
			LCD_vSend_string("duty:");
			LCD_vSend_char((duty_cycle/10)+48);
			LCD_vSend_char((duty_cycle%10)+48);
			LCD_vSend_char('%');
			LCD_movecursor(2,1);
			LCD_vSend_string("freq:");
			LCD_vSend_char((frequency/1000)+48);
			LCD_vSend_char(((frequency/100)%10)+48);
			LCD_vSend_char(((frequency/10)%10)+48);
			LCD_vSend_char((frequency%10)+48);
			LCD_vSend_string("HZ");
		}
		else
		{
			LCD_clearscreen();
			LCD_vSend_string("out of range");

		}

	while (1)
	{

	}

}
