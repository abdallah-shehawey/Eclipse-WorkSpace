################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../I2C.c \
../LCD.c \
../interface\ \ MC\ and\ EEPROM\ via\ I2C.c 

OBJS += \
./DIO.o \
./I2C.o \
./LCD.o \
./interface\ \ MC\ and\ EEPROM\ via\ I2C.o 

C_DEPS += \
./DIO.d \
./I2C.d \
./LCD.d \
./interface\ \ MC\ and\ EEPROM\ via\ I2C.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

interface\ \ MC\ and\ EEPROM\ via\ I2C.o: ../interface\ \ MC\ and\ EEPROM\ via\ I2C.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"interface  MC and EEPROM via I2C.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


