/*
 * main.c
 *
 *  Created on: Dec 9, 2024
 *      Author: Mega
 */

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
int main()
{
	DDRA = 0xff;
	while (1)
	{
		for (int i = 3 ; i >= 0; i--)
		{
			PORTA ^= (1 << i);
			PORTA ^= (1 << 7-i);
			_delay_ms(200);
		}
	}
}
