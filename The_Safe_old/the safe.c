#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "keypad_driver.h"
#include "LCD.h"
#include "EEPROM_interface.h"
#include "STD_MACROS.h"
#include "STD_TYPES.h"

#define EEPROM_STATUS_LOCATION         0x20
#define EEPROM_PASSWORD_LOCATION1 0x21
#define EEPROM_PASSWORD_LOCATION2 0x22
#define EEPROM_PASSWORD_LOCATION3 0x23
#define EEPROM_PASSWORD_LOCATION4 0x24
#define MAX_TRIES 2

char arr[4];

void set_password()
{
	LCD_clearscreen();
	LCD_vSend_string("set pass:");
	for (char i = 0; i < 4; i++)
	{
		char value;
		do
		{
			value = keypad_u8check_press();
		} while (value == NOTPRESSED);
		LCD_vSend_char(value);
		_delay_ms(500);
		LCD_movecursor(1, 10 + i);
		LCD_vSend_char('*');
		EEPROM_vWrite(EEPROM_PASSWORD_LOCATION1 + i, value);
	}
	EEPROM_vWrite(EEPROM_STATUS_LOCATION, 0x00);
}

int main(void) {
	DDRC = 0x00;
	PORTC = 0xff;
	unsigned char x;
	char value = NOTPRESSED;
	char flag = 0;
	char tries = MAX_TRIES;
	keypad_vInit();
	LCD_vInit();

	if (EEPROM_vRead(EEPROM_STATUS_LOCATION) == NOTPRESSED)
	{
		set_password();
	}

	while (flag == 0)
	{
		if (DIO_u8read('C', 0) == 0)
		{
			// Button pressed, reset the password
			EEPROM_vWrite(EEPROM_STATUS_LOCATION, NOTPRESSED);
			set_password();
			arr[0] = arr[1] = arr[2] = arr[3] = NOTPRESSED;
			LCD_clearscreen();
			LCD_vSend_string("check pass:");
		}
		arr[0] = arr[1] = arr[2] = arr[3] = NOTPRESSED;
		LCD_clearscreen();
		LCD_vSend_string("check pass:");
		for (char i = 0; i < 4; i++) {
			do {
				if (DIO_u8read('C', 0) == 0) {
					// Button pressed, reset the password
					EEPROM_vWrite(EEPROM_STATUS_LOCATION, NOTPRESSED);
					set_password();
					arr[0] = arr[1] = arr[2] = arr[3] = NOTPRESSED;
					LCD_clearscreen();
					LCD_vSend_string("check pass:");
					i = 0;
				}
				arr[i] = keypad_u8check_press();
			} while (arr[i] == NOTPRESSED);
			LCD_vSend_char(arr[i]);
			_delay_ms(500);
			LCD_movecursor(1, 12 + i);
			LCD_vSend_char('*');
		}

		if (EEPROM_vRead(EEPROM_PASSWORD_LOCATION1) == arr[0] &&
				EEPROM_vRead(EEPROM_PASSWORD_LOCATION2) == arr[1] &&
				EEPROM_vRead(EEPROM_PASSWORD_LOCATION3) == arr[2] &&
				EEPROM_vRead(EEPROM_PASSWORD_LOCATION4) == arr[3])
		{
			LCD_clearscreen();
			LCD_vSend_string("right password");
			LCD_movecursor(2, 1);
			LCD_vSend_string("safe opened");
			flag = 1;
		}
		else
		{
			tries--;
			if (tries > 0)
			{
				LCD_clearscreen();
				LCD_vSend_string("wrong password");
				_delay_ms(1000);
				LCD_clearscreen();
				LCD_vSend_string("tries left:");
				LCD_vSend_char(tries + '0');
				_delay_ms(1000);
			}
			else
			{
				LCD_clearscreen();
				LCD_vSend_string("wrong password");
				LCD_movecursor(2, 1);
				LCD_vSend_string("safe closed");
				flag = 1;
			}
		}
	}
}
