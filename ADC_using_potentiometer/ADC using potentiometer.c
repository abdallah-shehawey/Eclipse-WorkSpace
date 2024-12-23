/*
 * ADC.c
 *

 *  Author: Mohamed Zaghlol
 */ 

#include <avr/io.h>
#include "LED.h"
#include "ADC_driver.h"
int main(void)
{
	ADC_vinit();
	LED_vInit('D',0);
	LED_vInit('D',1);
	LED_vInit('D',2);
	LED_vInit('D',3);
	LED_vInit('D',4);
	LED_vInit('D',5);
	LED_vInit('D',6);
	LED_vInit('D',7);
    while(1)
    {
    PORTD=ADC_u16Read();   
    }
}
