/*
 * interrupt_with_spi.c
 *
 * Created: 10/31/2019 1:49:36 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "LED.h"
#include "spi_driver.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include <avr/interrupt.h>
int main(void)
{
	unsigned char x=0;
	LED_vInit('D',7);
	SPI_MasterInit();
	sei();
    while(x<10)
    {
        SPI_MasterTransmitchar(48+x);
		_delay_ms(1000);
		x++;
    }
}

ISR(SPI_STC_vect)
{
	LED_vToggle('D',7);
		
}

