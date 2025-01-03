/*
 * main.c
 *
 *      Created on: Aug 12, 2024
 *      Author: Mega
 */

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#include "LED_interface.h"
#include "TIMER_interface.h"

#include "util/delay.h"

int main()
{

	LED_config LED0 = {PORTA, PIN0, ACTIVE_HIGH};
	LED_config LED1 = {PORTA, PIN1, ACTIVE_HIGH};
	LED_config LED2 = {PORTA, PIN2, ACTIVE_HIGH};
	LED_vInit(LED0);
	LED_vInit(LED1);
	LED_vInit(LED2);
	u8 counter = 1;
	while (1)
	{
		_delay_ms(1000);
		if (counter % 1 == 0)
		{
			LED_vTog(LED0);
		}
		if (counter % 2 == 0)
		{
			LED_vTog(LED1);
		}
		if (counter % 3 == 0)
		{
			LED_vTog(LED2);
		}
		counter++;
	}
}
