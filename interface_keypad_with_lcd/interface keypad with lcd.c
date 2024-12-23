#define F_CPU 8000000UL
#include <util/delay.h>
#include "keypad_driver.h"
#include "LCD.h"
int main(void)
{
	LCD_vInit();
	keypad_vInit();
	char x;
    while(1)
    {
        x = keypad_u8check_press();
		if (x != NOTPRESSED)
		{
			LCD_vSend_char(x);	
		}
		_delay_ms(250);
    }
}



