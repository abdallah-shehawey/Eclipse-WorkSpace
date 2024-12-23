/*
 * temperature_sensor_using_LCD.c
 *
 * Created: 3/8/2018 3:06:02 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "ADC_driver.h"
#include "LCD.h"
char read_val;
unsigned short temp;
unsigned short volt;
int main(void)
{
	LCD_vInit();
	ADC_vinit();
	LCD_vSend_string("temp=");
	while(1)
	{

		volt = ADC_u16Read() * 2.5;
		if (volt >= 1000)
		{
			temp = (volt - 1000)/ 10;
			if (temp < 10)
			{
				LCD_movecursor(1, 6);
				LCD_vSend_char(temp + 48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
				LCD_vSend_char(' ');
			}
			else if (temp < 100)
			{
				LCD_movecursor(1, 6);
				LCD_vSend_char((temp/10) + 48);
				LCD_vSend_char((temp % 10) + 48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
			}
		}
		else
		{
			temp = (1000 - volt )/ 10;
			if (temp < 10)
			{
				LCD_movecursor(1, 6);
				LCD_vSend_char('-');
				LCD_vSend_char(temp + 48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
				LCD_vSend_char(' ');
			}
			else if (temp < 100)
			{
				LCD_movecursor(1, 6);
				LCD_vSend_char('-');
				LCD_vSend_char((temp/10) + 48);
				LCD_vSend_char((temp % 10) + 48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
			}
		}
	}
}

