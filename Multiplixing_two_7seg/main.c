/*
 * main.c
 *
 *  Created on: Jul 14, 2024
 *      Author: Mega
 */

#include <avr/io.h>
#include "seven segment.h"
#include <DIO.h>
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char counter = 0;
unsigned char number = 0;

int main(void)
{
	seven_seg_vinit('D'); // Initialize the seven-segment display on port D
	DIO_vsetPINDir('A', 0, 1); // Set PA0 as output
	DIO_vsetPINDir('A', 1, 1); // Set PA1 as output

	while (1)
	{
		// Display the tens digit
		seven_seg_write('D', number / 10);
		PORTA = 0b01;
		_delay_ms(10);
		PORTA = 0xff;

		// Display the units digit
		seven_seg_write('D', number % 10);
		PORTA = 0b10;
		_delay_ms(10);
		PORTA = 0xff;

		// Increment counter and number
		counter++;
		if (counter == 40)
		{
			counter = 0;
			number++;
			if (number == 100)
			{
				number = 0; // Reset to 0 after reaching 99
			}
		}
	}
}
