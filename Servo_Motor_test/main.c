/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Mega
 */

#define F_CPU 8000000UL
#include "STD_MACROS.h"
#include "STD_TYPES.h"

#include <util/delay.h>

#include "TIMER_interface.h"
#include "DIO_interface.h"

#include "Servo_Motor_interface.h"


void main()
{
	TIMER1_vInit();
	Servo_Motor_vInit();

	while (1)
	{

		Servo_Motor_vTimer1Degree(45);
		_delay_ms(1000);
		Servo_Motor_vTimer1Degree(0);
		_delay_ms(1000);

		Servo_Motor_vTimer1Degree(15);
		_delay_ms(1000);
		Servo_Motor_vTimer1Degree(90);
		_delay_ms(1000);
		Servo_Motor_vTimer1Degree(-15);
		_delay_ms(1000);
		Servo_Motor_vTimer1Degree(-90);
		_delay_ms(1000);
		Servo_Motor_vTimer1Degree(-45);
		_delay_ms(1000);

	}
}
