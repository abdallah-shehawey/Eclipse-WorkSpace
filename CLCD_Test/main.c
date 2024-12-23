/*
 * driver lcd.c
 *
 * Created: 10/17/2024 3:12:49 PM
 * Author : friends
 */ 

#include <avr/io.h>


int main(void)
{
	LCD_vInit();
    while (1) 
    {
    	LCD_vSend_char('A');
    }
}

