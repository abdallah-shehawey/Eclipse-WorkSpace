/*
 * DIO.c
 *
 * Created: 9/14/2024 10:16:26 PM
 *  Author: friends
 */ 
#include <avr/io.h>
#include "std_macro.h"
void DIO_vsetPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case'a' :
		if(1==direction)
		{
			SET_BIT(DDRA,pinnumber);
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);
		}
		break;
		case 'B':
		case'b' :
		if(1==direction)
		{
			SET_BIT(DDRB,pinnumber);
		}
		else
		{
			CLR_BIT(DDRB,pinnumber);
		}
		break;
		case 'C':
		case'c' :
		if(1==direction)
		{
			SET_BIT(DDRC,pinnumber);
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);
		}
		break;
		case 'D':
		case'd' :
		if(1==direction)
		{
			SET_BIT(DDRD,pinnumber);
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);
		}
		break;
		default:
		break;
		
	}
}
void DIO_WRITEBIN(unsigned char portname,unsigned char pinnumber,unsigned char out_value) 
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if(1==out_value)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		if(1==out_value)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		case 'c':
		if(1==out_value)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(1==out_value)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		default:
		break;
	}
}
void DIO_TOGGLEBIN(unsigned char portname,unsigned char pinnumber) 
{
	switch(portname)
	{
		case 'A' :
		case 'a' :
		TOG_BIT(PORTA,pinnumber);
		break;
		case 'B' :
		case 'b' :
		TOG_BIT(PORTB,pinnumber);
		break;
        case 'C' :
		case 'c' :
		TOG_BIT(PORTC,pinnumber);
		break;
		case 'D' :
		case 'd' :
		TOG_BIT(PORTD,pinnumber);
		break;
		default:
		break;
	}
}
unsigned char DIO_u8READBIN(unsigned char portname,unsigned char pinnumber)
{
	unsigned char return_val=0;
	switch(portname)
	{
		case 'A' :
		case 'a' :
		return_val=READ_BIT(PINA,pinnumber);
		break;
		case 'B' :
		case 'b' :
		return_val=READ_BIT(PINB,pinnumber);
		break;
		case 'C' :
		case 'c' :
		return_val=READ_BIT(PINC,pinnumber);
		break;
		case 'D' :
		case 'd' :
		return_val=READ_BIT(PIND,pinnumber);
		break;
		default:
		break;
	}
	return return_val;
	
}

void DIO_SET_PORTDIR(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		DDRA = direction;
		break;
		case 'B':
		case 'b':
		DDRB=direction;
		break;
		case 'C':
		case 'c':
		DDRC=direction;
		break;
		case 'D':
		case 'd':
		DDRD=direction;
		break;
		default:
		break;
	}
}
void DIO_WRITEPORT(unsigned char portname,unsigned char valueof_port)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA=valueof_port;
		break;
		case 'B':
		case 'b':
		PORTB=valueof_port;
		break;	
		case 'C':
		case 'c':
		PORTC=valueof_port;
		break;
		case 'D':
		case 'd':
		PORTD=valueof_port;
		break;
		default:
		break;	
	}
}
void DIO_TOGGELPORT(unsigned char portname)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA =~PORTA;
		//PORTA=PORTA^0xff;  or PORTA=PORTA^255;
		break;
		case 'B':
		case 'b':
		PORTB =~PORTB;
		//PORTB=PORTB^0xff;  or PORTB=PORTB^255;
		break;
		case 'C':
		case 'c':
		PORTC =~PORTC;
		//PORTC=PORTC^0xff;  or PORTC=PORTC^255;
		break;
		case 'D':
		case 'd':
		PORTD =~PORTD;
		//PORTD=PORTD^0xff;  or PORTD=PORTD^255;
		break;
		default:
		break;
	}
}
unsigned char DIO_READPORT(unsigned char portname)
{
	unsigned char return_val=0;
	switch(portname)
	{
		case 'A' :
		case 'a' :
		return_val=PINA;
		break;
		case 'B' :
		case 'b' :
		return_val=PINB;
		break;
		case 'C' :
		case 'c' :
		return_val=PINC;
		break;
		case 'D' :
		case 'd' :
		return_val=PIND;
		break;
		default:
		break;
	}
	return return_val;
}
void DIO_connect_pullup (unsigned char portname,unsigned char pinnumber,unsigned char connect_pullup)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if(1==connect_pullup)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		if(1==connect_pullup)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		case 'c':
		if(1==connect_pullup)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(1==connect_pullup)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		default:
		break;
	}
}

void DIO_Write_lownibble (unsigned char portname,unsigned char Value)
{
	Value&=0x0f;
	switch(portname)
	{
		case 'A' :
		case 'a' :
		PORTA&=0xf0;
		PORTA|=Value;
		break;
		case 'B' :
		case 'b' :
		PORTB&=0xf0;
		PORTB|=Value;
		break;
		case 'C' :
		case 'c' :
		PORTC&=0xf0;
		PORTC|=Value;
		break;
		case 'D' :
		case 'd' :
		PORTD&=0xf0;
		PORTD|=Value;
		break;
	}
}
void DIO_Write_highnibble (unsigned char portname,unsigned char Value)
{
	Value<<=4;
	switch(portname)
	{
		case 'A' :
		case 'a' :
		PORTA&=0x0f;
		PORTA|=Value;
		break;
		case 'B' :
		case 'b' :
		PORTB&=0x0f;
		PORTB|=Value;
		break;
		case 'C' :
		case 'c' :
		PORTC&=0x0f;
		PORTC|=Value;
		break;
		case 'D' :
		case 'd' :
		PORTD&=0x0f;
		PORTD|=Value;
		break;
	}
}


