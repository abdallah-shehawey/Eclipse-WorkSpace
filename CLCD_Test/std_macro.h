/*
 * std_macro.h
 *
 * Created: 9/14/2024 8:42:03 PM
 *  Author: friends
 */ 


#ifndef STD_MACRO_H_
#define STD_MACRO_H_
#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)      reg|=(1<<bit)
#define CLR_BIT(reg,bit)      reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)      reg^=(1<<bit)
#define READ_BIT(reg,bit)     ((reg&(1<<bit))>>bit)
#define ROR(reg,num)          reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)          reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num))
#define IS_BIT_SET(reg,bit)   (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)   !((reg&(1<<bit))>>bit)
#endif /* STD_MACRO_H_ */