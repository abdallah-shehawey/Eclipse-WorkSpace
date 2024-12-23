#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "keypad_driver.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
void keypad(void *pv);
void LCD(void *pv);

QueueHandle_t my_queue ;
unsigned char z;

int main(void)
{
	keypad_vInit();
	LCD_vInit();
	xTaskCreate(keypad,"M", 100, NULL, 2, NULL);
	xTaskCreate(LCD, "N", 100, NULL, 1, NULL);
	my_queue = xQueueCreate(5, sizeof(char));
	vTaskStartScheduler();
	
	while(1)
	{
		
	}
}
void keypad( void *pv )
{
	char x;
	while(1)
	{
		x = keypad_u8check_press();
		if(x != NOTPRESSED)
		{
			xQueueSend(my_queue, &x, 1000);
			_delay_ms(300);
			z++;
			if (z == 3)
			{
			vTaskDelay(1000);
			z = 0;
			}
		}
	}
}
void LCD( void *pv )
{
	char y;
	while(1)
	{
		xQueueReceive(my_queue, &y, 1000);
		LCD_vSend_char(y);
	}
}
