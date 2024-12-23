/*
 * Smart_Home.c
 *
 *  Created on: Aug 29, 2024
 *      Author: Mega
 */

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#include "../MCAL_Layer/DIO/DIO_interface.h"
#include "../MCAL_Layer/EEPROM/EEPROM_interface.h"
#include "../MCAL_Layer/USART/USART_interface.h"

#include "../HAL_Layer/CLCD/CLCD_interface.h"

#include "Security.h"

volatile u8 UserName_Length = 0, PassWord_Length = 0;
volatile u8 Error_State, KPD_Press;
volatile u8 Max_Tries = 3;

/*
 * USNL ==> User Name Length
 * PWL   ==> PassWord Length
 */




void main(void)
{
	UserName_Length = EEPROM_vRead(EEPROM_USNL_Location);
	PassWord_Length = EEPROM_vRead(EEPROM_PWL_Location);

	if(EEPROM_vRead(EEPROM_NoTries_Location) != NOTPRESSED)
	{
		Max_Tries = EEPROM_vRead(EEPROM_NoTries_Location);
	}
	else
	{

	}
	/* Initialize CLCD On PORTB And 4Bit Mode And Connected on Low Nibble */
	CLCD_vInit();

	/* Initialize USART to communicate with laptop */
	USART_vInit();

	CLCD_vSetPosition(1, 7);
	CLCD_vSendString("Welcome");
	_delay_ms(500);

	//if it's first login
	if(EEPROM_vRead(EEPROM_UserNameStatus) == NOTPRESSED)
	{
		CLCD_vSetPosition(2, 1);
		CLCD_vSendString("Please Sign UP");
		CLCD_vSendExtraChar(4, 15);
		CLCD_vSetPosition(4, 16);
		CLCD_vSendString(" : OK");
		while(1)
		{
			//wait in error page until press enter
			Error_State = USART_u8ReceiveData(&KPD_Press);
			if (Error_State == OK)
			{
				if (KPD_Press == 0x0D || KPD_Press == 0x0F)
				{
					break;
				}
			}
		}
		UserName_Set();
	}
	if(EEPROM_vRead(EEPROM_PassWordStatus) == NOTPRESSED)
	{
		PassWord_Set();
		CLCD_vClearScreen();
		CLCD_vSendString("Saved Successfully");
		CLCD_vSendExtraChar(4, 15);
		CLCD_vSetPosition(4, 16);
		CLCD_vSendString(" : OK");
		while(1)
		{
			//wait in error page until press enter
			Error_State = USART_u8ReceiveData(&KPD_Press);
			if (Error_State == OK)
			{
				if (KPD_Press == 0x0D || KPD_Press == 0x0F)
				{
					break;
				}
			}
		}
		CLCD_vClearScreen();
	}
	/*___________________________________________________________________________________________________________________*/

	if(Max_Tries == 0)
	{
		Error_TimeOut();
	}
	else
	{

	}

	while (1)
	{
		Sign_In();
		_delay_ms(1000);
	}
}

//======================================================================================================================================//

