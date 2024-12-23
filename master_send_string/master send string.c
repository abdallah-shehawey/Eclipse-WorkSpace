/*
 * master_send_string.c
 *
 * Created: 10/31/2019 12:17:44 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "spi_driver.h"
#define F_CPU 8000000UL
#include "util/delay.h"
int main(void)
{
	SPI_MasterInit();
	_delay_ms(500);
	SPI_MasterTransmitstring("mohamed zaghloul");
    while(1)
    {
   	
    }
}


