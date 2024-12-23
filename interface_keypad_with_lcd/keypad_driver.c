/*
 * LAB_1.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Mega
 */
#include "keypad_driver.h"
void keypad_vInit()
{
	DIO_set_port_direction(KB_Port, 0x0f);
	DIO_write_port(KB_Port, 0xf0);
}
char keypad_u8check_press()
{
	char keybad_button[4][4]={
			{'7','8','9','/'},
			{'4','5','6','*'},
			{'1','2','3','-'},
			{'A','0','=','+'}
	};
	char row,coloumn,x;
	char returnval=NOTPRESSED;
	for(row=0;row<4;row++)
	{
		DIO_write_port(KB_Port, 0x0f);
		DIO_write(KB_Port,row,0);

		for(coloumn=0;coloumn<4;coloumn++)
		{
			x = DIO_u8read(KB_Port,(coloumn+4));
			if(x == 0)
			{
				returnval = keybad_button[row][coloumn];
				break;
			}
		}
		if(x==0)
		{
			break;
		}
	}
	return returnval ;
}
