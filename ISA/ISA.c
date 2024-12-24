/*
 * ISA.c
 *  Created on: Jul 28, 2024
 *      Author: Mega
 */

#include <util/delay.h>

void display_number(unsigned char number);

const unsigned char Seg_Num[10] = {
    ~0x3F, // 0
    ~0x06, // 1
    ~0x5B, // 2
    ~0x4F, // 3
    ~0x66, // 4
    ~0x6D, // 5
    ~0x7D, // 6
    ~0x07, // 7
    ~0x7F, // 8
    ~0x6F  // 9
};

unsigned char OP, OP1, OP2, Result, port_value;

void main()
{
  *((volatile unsigned char *)0x3A)  = 0x00; /*INPUT PORTA*/                    ///DDRA
  *((volatile unsigned char *)0x3B)  = 0xFF; /*Internal PULL UP Resistor*/      ///PORTA
  *((volatile unsigned char *)0x37)  = 0xFF; /*for two 7 segments*/             ///DDRB
  *((volatile unsigned char *)0x34)  = 0xFF; /*for 7seg Enable*/                ///DDRC
  while (1)
  {
    while (1)
    {

      //Read all bins
      port_value = ~*((volatile unsigned char *)0x39);                          ///PINA
      *((volatile unsigned char *)0x32) = ~*((volatile unsigned char *)0x39);   ///PORTD
      //INST Format
      OP  = ((port_value & (1 << 7)) | (port_value & (1 << 6))) >> 6;                           //Port Value & 11000000
      OP1 = ((port_value & (1 << 5)) | (port_value & (1 << 4)) |(port_value & (1 << 3))) >> 3;  //Port Value & 00111000
      OP2 = ((port_value & (1 << 2)) | (port_value & (1 << 1)) |(port_value & (1 << 0)));       //Port Value & 00000111
      //Check operation
      switch (OP)
      {
      case 0:
        Result = OP1 + OP2;
        break;
      case 1:
        Result = OP1 - OP2;
        break;
      case 2:
        Result = OP1 * OP2;
        break;
      case 3:
        if (OP2 == 0)
        {
          Result = 'E';
        }
        else
        {
          Result = OP1 / OP2;
        }
        break;
      default:
        break;
      }
      display_number(Result);
    }
  }
}

void display_number(unsigned char number)
{
  if (number == 'E')
  {
    *((volatile unsigned char *)0x38) = 0b00000110;                             ///PORTB
    *((volatile unsigned char *)0x35) = 0b00000011;                             ///PORTC
  }
  else
  {
    unsigned char digit1 = number / 10;
    unsigned char digit2 = number % 10;

    *((volatile unsigned char *)0x38) = Seg_Num[digit1];                        ///PORTB
    *((volatile unsigned char *)0x35) = 0b00000001;                             ///PORTC
    _delay_ms(1);
    *((volatile unsigned char *)0x35) = 0x00;

    *((volatile unsigned char *)0x38) = Seg_Num[digit2];                        ///PORTB
    *((volatile unsigned char *)0x35) = 0b00000010;                             ///PORTC
    _delay_ms(1);
    *((volatile unsigned char *)0x35) = 0x00;
  }
}
