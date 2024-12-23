#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "seven segment.h"
#include "LCD.h"
#include "keypad_driver.h"
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
volatile unsigned char seconds_counter=0;
volatile unsigned char flag = 0;
volatile unsigned char counter = 0;
volatile unsigned char minutes_counter=0,hours_counter=12;
volatile unsigned char value,first_digit,second_digit, day_time, mode;
void Set_Time();
void select_mode();

//===================================================================/

int main(void)
{
	mode = '1';
	keypad_vInit();
	LCD_vInit();
	seven_seg_vinit('B');
	SET_BIT   (DDRC,0);
	SET_BIT   (DDRC,1);
	SET_BIT   (DDRC,2);
	SET_BIT   (DDRC,3);
	SET_BIT   (DDRC,4);
	SET_BIT   (DDRC,5);
	SET_BIT   (DDRA, 3);
	CLR_BIT   (PORTA, 3);
	LCD_vSend_string("1 - set time");
	LCD_movecursor(2,1);
	LCD_vSend_string("2 - select mode");
	timer2_overflow_init_interrupt();
	while(1)
	{
		value = keypad_u8check_press();
		if (value != NOTPRESSED)
		{
			switch(value)
			{
			case '1':
				Set_Time();
				break;
			case '2':
				select_mode();
				break;
			default:
				LCD_clearscreen();
				LCD_vSend_string("wrong choice");
				_delay_ms(1000);
				LCD_clearscreen();
				LCD_vSend_string("1 - set time");
				LCD_movecursor(2,1);
				LCD_vSend_string("2 - select mode");
				break;
			}
		}
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,0);
		seven_seg_write('B',seconds_counter%10);
		_delay_ms(5);

		SET_BIT(PORTC,0);
		CLR_BIT(PORTC,1);
		seven_seg_write('B',seconds_counter/10);
		_delay_ms(5);

		SET_BIT(PORTC,1);
		CLR_BIT(PORTC,2);
		seven_seg_write('B',minutes_counter%10);
		_delay_ms(5);

		SET_BIT(PORTC,2);
		CLR_BIT(PORTC,3);
		seven_seg_write('B',minutes_counter/10);
		_delay_ms(5);

		SET_BIT(PORTC,3);
		CLR_BIT(PORTC,4);
		seven_seg_write('B',hours_counter%10);
		_delay_ms(5);

		SET_BIT(PORTC,4);
		CLR_BIT(PORTC,5);
		seven_seg_write('B',hours_counter/10);
		_delay_ms(5);
	}
}

//===================================================================/

void Set_Time()
{
	mode_select:
	LCD_clearscreen();
	LCD_vSend_string("1 - 12-hour time");
	LCD_movecursor(2, 1);
	LCD_vSend_string("2 - 24-hour time");
	do
	{
		mode = keypad_u8check_press();
	}while (mode == NOTPRESSED);
	_delay_ms(300);

	if (mode != '1' && mode != '2')
	{
		LCD_clearscreen();
		LCD_vSend_string("wrong choise");
		_delay_ms (300);
		goto mode_select;
	}

	LCD_clearscreen();
	LCD_vSend_char(hours_counter/10 +48);
	LCD_vSend_char(hours_counter%10 +48);
	LCD_vSend_string(" : ");
	LCD_vSend_char(minutes_counter/10 + 48);
	LCD_vSend_char(minutes_counter%10 + 48);
	LCD_vSend_string(" : ");
	LCD_vSend_char(seconds_counter/10 + 48);
	LCD_vSend_char(seconds_counter%10 + 48);
	LCD_vSend_char(' ');

	if (mode == '1')
	{
		if (DIO_u8read('A', 3) == 1)
		{
			LCD_vSend_string("AM");
		}
		else
		{
			LCD_vSend_string("PM");
		}
	}
	LCD_movecursor(1,1);
	_delay_ms(500);
	do
	{
		first_digit=keypad_u8check_press();
	} while (first_digit==NOTPRESSED);
	LCD_movecursor(1,1);
	LCD_vSend_char(first_digit);
	_delay_ms(300);
	do
	{
		second_digit=keypad_u8check_press();
	} while (second_digit==NOTPRESSED);
	LCD_vSend_char(second_digit);
	_delay_ms(300);
	hours_counter=(second_digit-48)+10*(first_digit-48);
	if (mode == '1')
	{
		if (hours_counter > 12 || hours_counter == 0)
		{
			hours_counter = 12;
			LCD_movecursor(1, 1);
			LCD_vSend_char(hours_counter/10 +48);
			LCD_vSend_char(hours_counter%10 +48);
		}
	}
	else if (mode == '2')
	{
		if (hours_counter  > 23)
		{
			hours_counter = 0;
			LCD_movecursor(1, 1);
			LCD_vSend_char(hours_counter/10 +48);
			LCD_vSend_char(hours_counter%10 +48);
		}
	}
	else
	{

	}
	LCD_movecursor(1,6);
	do
	{
		first_digit=keypad_u8check_press();
	} while (first_digit==NOTPRESSED);
	LCD_vSend_char(first_digit);
	_delay_ms(300);
	do
	{
		second_digit=keypad_u8check_press();

	} while (second_digit==NOTPRESSED);
	LCD_vSend_char(second_digit);
	_delay_ms(300);
	minutes_counter=(second_digit-48)+10*(first_digit-48);
	if (minutes_counter > 59)
	{
		minutes_counter = 0;
		LCD_movecursor(1,6);
		LCD_vSend_char(minutes_counter/10 + 48);
		LCD_vSend_char(minutes_counter%10 + 48);
	}
	LCD_movecursor(1,11);
	do
	{
		first_digit=keypad_u8check_press();

	} while (first_digit==NOTPRESSED);
	LCD_vSend_char(first_digit);
	_delay_ms(300);
	do
	{
		second_digit=keypad_u8check_press();

	} while (second_digit==NOTPRESSED);
	LCD_vSend_char(second_digit);
	_delay_ms(300);
	seconds_counter=(second_digit-48)+10*(first_digit-48);
	if (seconds_counter > 59)
	{
		seconds_counter = 0;
		LCD_movecursor(1,11);
		LCD_vSend_char(seconds_counter/10 + 48);
		LCD_vSend_char(seconds_counter%10 + 48);
	}
	if (mode == '1')
	{
		mode:
		LCD_movecursor(2, 1);
		LCD_vSend_string("1 : AM    2 : PM");
		do
		{
			day_time = keypad_u8check_press();
		}while (day_time == NOTPRESSED);
		_delay_ms(300);
		if (day_time == '1')
		{
			SET_BIT(PORTA, 3);
		}
		else if (day_time == '2')
		{
			CLR_BIT(PORTA, 3);
		}
		else
		{
			LCD_clearscreen();
			LCD_vSend_string("Wrong Choise");
			_delay_ms(500);
			LCD_clearscreen();
			LCD_movecursor(1, 1);
			LCD_vSend_char(hours_counter/10 +48);
			LCD_vSend_char(hours_counter%10 +48);
			LCD_vSend_string(" : ");
			LCD_vSend_char(minutes_counter/10 + 48);
			LCD_vSend_char(minutes_counter%10 + 48);
			LCD_vSend_string(" : ");
			LCD_vSend_char(seconds_counter/10 + 48);
			LCD_vSend_char(seconds_counter%10 + 48);
			if (DIO_u8read('A', 3) == 1)
			{
				LCD_vSend_string(" AM");
			}
			else
			{
				LCD_vSend_string("PM");
			}
			goto mode;
		}
	}
	else
	{

	}
	LCD_clearscreen();
	LCD_vSend_string("1 - set time");
	LCD_movecursor(2,1);
	LCD_vSend_string("2 - select mode");
}

//===================================================================/

void select_mode()
{

	mode_choise:
	LCD_clearscreen();
	LCD_vSend_string("1 - 12-hour time");
	LCD_movecursor(2, 1);
	LCD_vSend_string("2 - 24-hour time");

	do
	{
		mode = keypad_u8check_press();
	}while (mode == NOTPRESSED);
	_delay_ms(300);

	if (mode == '1')
	{
		if (hours_counter > 12 )
		{
			hours_counter -= 12;
		}
		else if (hours_counter == 0)
		{
			hours_counter += 12;
		}
		else
		{

		}
	}
	else if (mode == '2')
	{
		if (hours_counter == 12 && DIO_u8read('A', 3) == 1)
		{
			hours_counter = 0;
		}
		else if (DIO_u8read('A', 3) == 0)
		{
			hours_counter += 12;
		}
		else
		{

		}
	}
	else
	{
		LCD_clearscreen();
		LCD_vSend_string("Wrong choise");
		_delay_ms(500);
		goto mode_choise;
	}
	LCD_clearscreen();
	LCD_vSend_string("1 - set time");
	LCD_movecursor(2,1);
	LCD_vSend_string("2 - select mode");
}

//===================================================================/

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
	flag = 0;

	if (seconds_counter == 60)
	{
		seconds_counter = 0;
		minutes_counter++;
	}
	if (minutes_counter == 60)
	{
		minutes_counter=0;
		hours_counter++;
	}
	if (mode == '1')
	{
		if (hours_counter== 13)
		{
			hours_counter= 1;
		}
		if (hours_counter == 12 && minutes_counter == 0 && seconds_counter == 0 && flag == 0)
		{
			TOG_BIT(PORTA, 3);
			flag = 1;
		}
	}
	if (mode == '2')
	{
		if (hours_counter == 24)
		{
			hours_counter = 0;
		}
		else
		{

		}
		if (hours_counter < 12)
		{
			SET_BIT(PORTA, 3);
		}
		else if (hours_counter >= 12)
		{
			CLR_BIT(PORTA, 3);
		}
		else
		{

		}
	}
}
