/*
 * OC0_with__fast__PWM_Mode.c
 *
 * Created: 9/26/2019 4:14:56 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "timer.h"
int main(void)
{
	timer_wave_fastPWM();
    while(1)
    {
        
    }
}