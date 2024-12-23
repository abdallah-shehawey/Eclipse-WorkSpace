/*
 * main.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mega
 */

#include "util/delay.h"

#include "CLCD_interface.h"

#include "STD_TYPES.h"
#include "STD_MACROS.h"


int main()
{
    CLCD_vInit();
    while (1)
    {
        CLCD_vSendString("ABDallah");
        _delay_ms(500);
    }
}


