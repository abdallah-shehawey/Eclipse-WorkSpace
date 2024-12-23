/*
 * interrupt_with_ADC.c
 *
 * Created: 8/15/2019 5:13:48 AM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "LED.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "ADC_driver.h"
#include "std_macros.h"
#include <avr/interrupt.h>
int main(void)
{
	ADC_vinit();
	sei();
	SET_BIT(ADCSRA,ADIE);
	LED_vInit('D',0);
	LED_vInit('D',1);
    while(1)
    {
        SET_BIT(ADCSRA,ADSC);
		_delay_ms(.5);
		PORTD=0X02;
		_delay_ms(1000);
    }
}


 ISR(ADC_vect)
 {
	PORTD=0X01;
	_delay_ms(1000);
 }
