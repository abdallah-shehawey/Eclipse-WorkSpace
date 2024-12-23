/*
 * DIO.h
 *
 * Created: 9/14/2024 10:16:49 PM
 *  Author: friends
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_vsetPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction);
void DIO_WRITEBIN(unsigned char portname,unsigned char pinnumber,unsigned char out_value);
void DIO_TOGGLEBIN(unsigned char portname,unsigned char pinnumber);
unsigned char DIO_u8READBIN(unsigned char portname,unsigned char pinnumber);
void DIO_SET_PORTDIR(unsigned char portname,unsigned char direction);
void DIO_WRITEPORT(unsigned char portname,unsigned char valueof_port);

void DIO_TOGGELPORT(unsigned char portname);
unsigned char DIO_READPORT(unsigned char portname);
void DIO_connect_pullup (unsigned char portname,unsigned char pinnumber,unsigned char connect_pullup);
void DIO_Write_lownibble (unsigned char portname,unsigned char value);
void DIO_Write_highnibble (unsigned char portname,unsigned char Value);
#endif /* DIO_H_ */