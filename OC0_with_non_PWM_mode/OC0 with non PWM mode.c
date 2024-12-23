/*
 * OC0_with_non_PWM_mode.c
 *
 * Created: 9/26/2019 12:18:59 AM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "timer.h"
int main(void)
{
	timer_wave_nonPWM();
    while(1)
    {
       
    }
}