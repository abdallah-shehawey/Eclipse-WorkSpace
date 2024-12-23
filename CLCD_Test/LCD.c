/*
 * LCD.c
 *
 * Created: 10/17/2024 3:17:03 PM
 *  Author: friends
 */ 
#include "LCD.h"
#define F_CPU 8000000UL 
#include <util/delay.h>

void LCD_vInit(void)
{
	_delay_ms(200);
	#if defined EIGHT_BITS_MODE
	DIO_SET_PORTDIR(NAME_DATA_PORT, 0XFF);
	DIO_vsetPINDir(NAME_CONTROL_PORT,EN, 1);
	DIO_vsetPINDir(NAME_CONTROL_PORT,RW, 1);
	DIO_vsetPINDir(NAME_CONTROL_PORT,RS,1);
	DIO_WRITEBIN(NAME_CONTROL_PORT,RW,0);
	LCD_vSend_cmd(EIGHT_BIT_MODE);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);
    LCD_vSend_cmd(CLER_SCREAN);
	LCD_vSend_cmd(ENTRY_MODE);
	
	
	#elif defined FOUR_BITS_MODE
	
	unsigned char i_pin;
	if(i_pin=START_PIN,i_pin<=3,i_pin++)
	{
		DIO_vsetPINDir(NAME_DATA_PORT,i_pin,1);
	}
	DIO_vsetPINDir(NAME_CONTROL_PORT,EN,1);
	DIO_vsetPINDir(NAME_CONTROL_PORT,RW,1);
	DIO_vsetPINDir(NAME_CONTROL_PORT,RS,1);
	DIO_WRITEBIN(NAME_CONTROL_PORT,RW,0);
	LCD_vSend_cmd(RETURNED_HOME);
	LCD_vSend_cmd(FOUR_BIT_MODE);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);
	LCD_vSend_cmd(CLER_SCREAN);
	LCD_vSend_cmd(ENTRY_MODE);
	
	#endif
}
void ENABLE (void)
{
	DIO_WRITEBIN(NAME_CONTROL_PORT,EN,1);
	_delay_ms(2);
	DIO_WRITEBIN(NAME_CONTROL_PORT,EN,0);
	_delay_ms(2);
}
void LCD_vSend_cmd(unsigned char cmd)
{
	#if defined EIGHT_BITS_MODE
	DIO_WRITEPORT(NAME_DATA_PORT,cmd);
    DIO_WRITEBIN(NAME_CONTROL_PORT,RS,0);
	ENABLE();

	#elif defined FOUR_BITS_MODE
	DIO_Write_highnibble(NAME_DATA_PORT,cmd>>4);
    DIO_WRITEBIN(NAME_CONTROL_PORT,RS,0);
	ENABLE();
	DIO_Write_highnibble(NAME_DATA_PORT,cmd);
	ENABLE();
	#endif
	_delay_ms(1);

}
void LCD_vSend_char(unsigned char data_char)
{
	#if defined EIGHT_BITS_MODE
	DIO_WRITEPORT(NAME_DATA_PORT,data_char);
	DIO_WRITEBIN(NAME_CONTROL_PORT,RS,1);
	ENABLE();

	#elif defined FOUR_BITS_MODE
	DIO_Write_highnibble(NAME_DATA_PORT,data_char>>4);
	DIO_WRITEBIN(NAME_CONTROL_PORT,RS,1);
	ENABLE();
	DIO_Write_highnibble(NAME_DATA_PORT,data_char);
	ENABLE();
	#endif
	_delay_ms(1);

}
void LCD_vSend_string (char*data_string)
{

	while ((*data_string)!='\0')
	{
		LCD_vSend_char(*data_string);
		data_string++;
	}
}
void LCD_vclean_cursor(void)
{
	LCD_vSend_cmd(CLER_SCREAN);
	_delay_ms(10);
}
void LCD_movecursor( char Row, char Coloum)
{
	unsigned char data;
	if(Row<1||Row>2||Coloum<1||Coloum>16)
	{
		data=STANDER_PLACE;
	}
	else if (1==Row)
	{
		data= 0x80+Coloum-1;
	}
	else if (2==Row)
	{
		data= 0xC0+Coloum-1;
	}
	LCD_vSend_cmd(data);
}
	
