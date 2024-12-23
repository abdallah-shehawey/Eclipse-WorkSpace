/*
 * LCD.h
 *
 * Created: 10/17/2024 3:18:06 PM
 *  Author: friends
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "lcd config.h"
#define STANDER_PLACE 0x80
#define CLER_SCREAN 0x01
#define RETURNED_HOME 0x02
#define CURSOR_ON_DISPLAY_ON 0x0E
#define ENTRY_MODE 0x06
#define FOUR_BIT_MODE 0x28
#define EIGHT_BIT_MODE 0x38
#if defined EIGHT_BITS_MODE
#define NAME_DATA_PORT 'A'
#define NAME_CONTROL_PORT 'C'

#define EN 0
#define RS 1
#define RW 2
#elif defined FOUR_BITS_MODE
#define NAME_DATA_PORT 'D'
#define START_PIN 1
#define NAME_CONTROL_PORT 'B'

#define EN 0
#define RS 1
#define RW 2
#endif
void LCD_vInit(void);
void ENABLE(void);
void LCD_vSend_cmd(unsigned char cmd);
void LCD_vSend_char(unsigned char data_char);
void LCD_vSend_string (char *data_string);
void LCD_vclean_cursor(void);
void LCD_movecursor( char Row, char Coloum);
#endif /* LCD_H_ */