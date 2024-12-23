#include <util\delay.h>
#include <avr\io.h>
#include <time.h>


int main (void)
{
	DDRD = 0xff;
	DDRC = 0xff;
	unsigned char Seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7f, 0x6f};
	unsigned char j = 0;
	while (1)
	{
		for (unsigned char i = 0; i <= 10;  i++)
		{
			if (i > 9)
			{
				i = 0;
				j++;
				if (j > 9)
				{
					j = 0;
				}
			}
			PORTD = Seg[j];
			PORTC = Seg[i];
			_delay_ms(200);
		}
	}
}
/*
#include <util\delay.h>
#include <avr\io.h>

int main (void)
{
	PORTA |= (1 << 3);
	DDRA &=~ (1<<3);

	DDRA |= ((1 << 5) | (1 << 6));
	while (1)
	{
		if (((PINA >> 3) & 1 ) == 0 )
		{
			PORTA |= (1 << 5);
			PORTA &=~ (1 << 6);
		}
		else
		{
			PORTA |= (1 << 6);
			PORTA &=~ (1 << 5);
		}
	}
}
 */
